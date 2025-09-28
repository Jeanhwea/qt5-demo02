#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <QDateTime>
#include <QFile>
#include <QMutex>
#include <QObject>
#include <QString>
#include <QTextStream>

// 日志级别枚举
enum LogLevel
{
    Debug,
    Info,
    Warning,
    Error,
    Fatal
};

class Logger : public QObject
{
    Q_OBJECT
public:
    // 获取单例实例
    static Logger *getInstance();

    // 设置日志文件路径
    void setLogFilePath(const QString &path);

    // 设置是否输出到控制台
    void setConsoleOutput(bool enable);

    // 设置日志级别阈值
    void setLogLevel(LogLevel level);

    // 日志输出函数
    void log(LogLevel level, const QString &message, const char *file = nullptr,
             int line = 0);

// 便捷的日志宏会自动传入文件名和行号
#define LOG_DEBUG(msg) Logger::getInstance()->log(Debug, msg, __FILE__, __LINE__)
#define LOG_INFO(msg) Logger::getInstance()->log(Info, msg, __FILE__, __LINE__)
#define LOG_WARN(msg) Logger::getInstance()->log(Warning, msg, __FILE__, __LINE__)
#define LOG_ERROR(msg) Logger::getInstance()->log(Error, msg, __FILE__, __LINE__)
#define LOG_FATAL(msg) Logger::getInstance()->log(Fatal, msg, __FILE__, __LINE__)

private:
    // 单例模式私有构造函数
    explicit Logger(QObject *parent = nullptr);
    ~Logger() override;

    // 禁止复制和赋值
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    // 格式化日志消息
    QString formatLogMessage(LogLevel level, const QString &message, const char *file,
                             int line);

    // 级别转字符串
    QString logLevelToString(LogLevel level);

    // 级别转颜色代码(控制台输出用)
    QString logLevelToColor(LogLevel level);

private:
    static Logger *m_instance; // 单例实例
    QFile m_logFile;           // 日志文件
    QTextStream m_fileStream;  // 文件输出流
    bool m_consoleOutput;      // 是否输出到控制台
    LogLevel m_logLevel;       // 日志级别阈值
    QMutex m_mutex;            // 线程安全锁
};

#endif /* End of _LOGGER_H_ */
