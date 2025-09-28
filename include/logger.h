#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <QDateTime>
#include <QFile>
#include <QMutex>
#include <QObject>
#include <QString>
#include <QTextStream>

enum LogLevel { Debug, Info, Warning, Error, Fatal };

class Logger : public QObject {
  Q_OBJECT
public:
  static Logger *getInstance();
  void setLogFilePath(const QString &path);
  void setConsoleOutput(bool enable);
  void setLogLevel(LogLevel level);
  void log(LogLevel level, const QString &message, const char *file = nullptr,
           int line = 0);

#define LOG_DEBUG(msg)                                                         \
  Logger::getInstance()->log(Debug, msg, __FILE__, __LINE__)
#define LOG_INFO(msg) Logger::getInstance()->log(Info, msg, __FILE__, __LINE__)
#define LOG_WARN(msg)                                                          \
  Logger::getInstance()->log(Warning, msg, __FILE__, __LINE__)
#define LOG_ERROR(msg)                                                         \
  Logger::getInstance()->log(Error, msg, __FILE__, __LINE__)
#define LOG_FATAL(msg)                                                         \
  Logger::getInstance()->log(Fatal, msg, __FILE__, __LINE__)

private:
  explicit Logger(QObject *parent = nullptr);
  ~Logger() override;

  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;
  QString formatLogMessage(LogLevel level, const QString &message,
                           const char *file, int line);
  QString logLevelToString(LogLevel level);
  QString logLevelToColor(LogLevel level);

private:
  static Logger *m_instance;
  QFile m_logFile;
  QTextStream m_fileStream;
  bool m_consoleOutput;
  LogLevel m_logLevel;
  QMutex m_mutex;
};

#endif /* End of _LOGGER_H_ */
