#include "logger.h"

#include <QDebug>
#include <QDir>

Logger *Logger::m_instance = nullptr;

Logger::Logger(QObject *parent)
    : QObject(parent), m_consoleOutput(true), m_logLevel(Debug) {
  QString logDir = QDir::currentPath() + "/logs";
  if (!QDir(logDir).exists()) {
    QDir().mkpath(logDir);
  }

  QString dateString = QDateTime::currentDateTime().toString("yyyyMMdd.hh");
  QString fileName = logDir + "/" + dateString + ".log";
  setLogFilePath(fileName);
}

Logger::~Logger() {
  if (m_logFile.isOpen()) {
    m_logFile.close();
  }
}

Logger *Logger::getInstance() {
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
  if (!m_logFile.open(QIODevice::WriteOnly | QIODevice::Append |
                      QIODevice::Text)) {
    qWarning() << "Failed to open file: " << m_logFile.errorString();
  } else {
    m_fileStream.setDevice(&m_logFile);
  }
}

void Logger::setConsoleOutput(bool enable) {
  QMutexLocker locker(&m_mutex);
  m_consoleOutput = enable;
}

void Logger::setLogLevel(LogLevel level) {
  QMutexLocker locker(&m_mutex);
  m_logLevel = level;
}

void Logger::log(LogLevel level, const QString &message, const char *file,
                 int line) {
  QMutexLocker locker(&m_mutex);

  if (level < m_logLevel) {
    return;
  }

  QString formattedMessage = formatLogMessage(level, message, file, line);

  if (m_logFile.isOpen()) {
    m_fileStream << formattedMessage << Qt::endl;
    m_fileStream.flush();
  }

  if (m_consoleOutput) {
    QString consoleMessage =
        logLevelToColor(level) + formattedMessage + "\033[0m";
    qDebug().noquote() << consoleMessage;
  }

  if (level == Fatal) {
    // qApp->exit(1);
  }
}

QString Logger::formatLogMessage(LogLevel level, const QString &message,
                                 const char *file, int line) {
  QString timeStr =
      QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz");

  QString logMessage =
      QString("[%1] [%2] ").arg(timeStr).arg(logLevelToString(level));

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
  case Warning:
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
  // ANSI 颜色代码，用于控制台彩色输出
  switch (level) {
  case Debug:
    return "\033[37m"; // 白色
  case Info:
    return "\033[32m"; // 绿色
  case Warning:
    return "\033[33m"; // 黄色
  case Error:
    return "\033[31m"; // 红色
  case Fatal:
    return "\033[1;31m"; // 亮红色
  default:
    return "\033[0m"; // 默认颜色
  }
}
