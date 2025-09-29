#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QMutex>
#include <QObject>
#include <QString>
#include <QTextStream>

enum LogLevel { Debug, Info, Warn, Error, Fatal };

class Logger : public QObject {
  Q_OBJECT
public:
  static Logger *instance();
  void setLogFilePath(const QString &path);
  void setConsoleOutput(bool enable);
  void setLogLevel(LogLevel level);
  void log(LogLevel level, const QString &message, const char *file = nullptr, int line = 0);

#define LOG_D(msg) Logger::instance()->log(Debug, msg, __FILE__, __LINE__)
#define LOG_I(msg) Logger::instance()->log(Info, msg, __FILE__, __LINE__)
#define LOG_W(msg) Logger::instance()->log(Warn, msg, __FILE__, __LINE__)
#define LOG_E(msg) Logger::instance()->log(Error, msg, __FILE__, __LINE__)
#define LOG_F(msg) Logger::instance()->log(Fatal, msg, __FILE__, __LINE__)

private:
  explicit Logger(QObject *parent = nullptr);
  ~Logger() override;

  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

  QString fmt(LogLevel level, const QString &message, const char *file, int line);
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
