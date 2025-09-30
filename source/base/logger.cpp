#include "base/logger.h"

#include "base/consts.h"

#include <QApplication>
#include <QDebug>
#include <QDir>

Logger *Logger::m_instance = nullptr;

Logger::Logger(QObject *parent) : QObject(parent), m_consoleOutput(true), m_logLevel(Debug) {
  QString logDir = QDir::currentPath() + "/logs";
  if (!QDir(logDir).exists()) {
    QDir().mkpath(logDir);
  }

  QString dateStr = QDateTime::currentDateTime().toString("yyyyMMdd.hh");
  QString fileName = QString("%1/%2.log").arg(logDir).arg(dateStr);
  setLogFilePath(fileName);
}

Logger::~Logger() {
  if (m_logFile.isOpen()) {
    m_logFile.close();
  }
}

Logger *Logger::instance() {
  if (!m_instance) {
    m_instance = new Logger();
  }
  return m_instance;
}

void Logger::setLogFilePath(const QString &path) {
  QMutexLocker locker(&m_mutex);

  if (m_logFile.isOpen()) {
    m_logFile.close();
  }

  m_logFile.setFileName(path);
  if (!m_logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
    qWarning() << "Failed to open file: " << m_logFile.errorString();
  } else {
    m_fileStream.setDevice(&m_logFile);
  }

  qDebug() << "Log to file:" << path;
}

void Logger::setConsoleOutput(bool enable) {
  QMutexLocker locker(&m_mutex);
  m_consoleOutput = enable;
}

void Logger::setLogLevel(LogLevel level) {
  QMutexLocker locker(&m_mutex);
  m_logLevel = level;
}

void Logger::log(LogLevel level, const QString &message, const char *file, int line) {
  QMutexLocker locker(&m_mutex);

  if (level < m_logLevel) {
    return;
  }

  QString formattedMessage = fmt(level, message, file, line);

  if (m_logFile.isOpen()) {
    m_fileStream << formattedMessage << Qt::endl;
    m_fileStream.flush();
  }

  if (m_consoleOutput) {
    QString consoleMessage = logLevelToColor(level) + formattedMessage + "\033[0m";
    qDebug().noquote() << consoleMessage;
  }

  if (level == Fatal) {
    qApp->exit(errcode::FATAL_ERROR);
  }
}

QString Logger::fmt(LogLevel level, const QString &message, const char *file, int line) {
  QString timeStr = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz");

  QString logMessage = QString("[%1] [%2] ").arg(timeStr).arg(logLevelToString(level));

  if (file && line > 0) {
    QString fileName = QFileInfo(QString(file)).fileName();
    logMessage += QString("[%1:%2] ").arg(fileName).arg(line);
  }

  logMessage += message;

  return logMessage;
}

QString Logger::logLevelToString(LogLevel level) {
  switch (level) {
  case Debug:
    return "DEBUG";
  case Info:
    return "INFO";
  case Warn:
    return "WARNING";
  case Error:
    return "ERROR";
  case Fatal:
    return "FATAL";
  default:
    return "UNKNOWN";
  }
}

QString Logger::logLevelToColor(LogLevel level) {
  switch (level) {
  case Debug:
    return colors::WHITE;
  case Info:
    return colors::GREEN;
  case Warn:
    return colors::YELLOW;
  case Error:
    return colors::RED;
  case Fatal:
    return colors::BRIGHT_RED;
  default:
    return colors::DEFAULT;
  }
}
