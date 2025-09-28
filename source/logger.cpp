#include "logger.h"
#include <QDebug>
#include <QDir>

// 初始化静态成员
Logger *Logger::m_instance = nullptr;

Logger::Logger(QObject *parent) :
    QObject(parent), m_consoleOutput(true), m_logLevel(Debug)
{
    // 默认日志路径: 应用程序所在目录/logs/当前日期.log
    QString logDir = QDir::currentPath() + "/logs";
    if (!QDir(logDir).exists()) {
        QDir().mkpath(logDir);
    }

    QString fileName =
        logDir + "/" + QDateTime::currentDateTime().toString("yyyyMMdd.hh") + ".log";
    setLogFilePath(fileName);
}

Logger::~Logger()
{
    if (m_logFile.isOpen()) {
        m_logFile.close();
    }
}

Logger *Logger::getInstance()
{
    if (!m_instance) {
        m_instance = new Logger();
    }
    return m_instance;
}

void Logger::setLogFilePath(const QString &path)
{
    QMutexLocker locker(&m_mutex);

    if (m_logFile.isOpen()) {
        m_logFile.close();
    }

    m_logFile.setFileName(path);
    if (!m_logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        qWarning() << "无法打开日志文件:" << m_logFile.errorString();
    } else {
        m_fileStream.setDevice(&m_logFile);
    }
}

void Logger::setConsoleOutput(bool enable)
{
    QMutexLocker locker(&m_mutex);
    m_consoleOutput = enable;
}

void Logger::setLogLevel(LogLevel level)
{
    QMutexLocker locker(&m_mutex);
    m_logLevel = level;
}

void Logger::log(LogLevel level, const QString &message, const char *file, int line)
{
    QMutexLocker locker(&m_mutex);

    // 如果日志级别低于阈值，则不输出
    if (level < m_logLevel) {
        return;
    }

    // 格式化日志消息
    QString formattedMessage = formatLogMessage(level, message, file, line);

    // 输出到文件
    if (m_logFile.isOpen()) {
        m_fileStream << formattedMessage << Qt::endl;
        m_fileStream.flush(); // 确保立即写入文件
    }

    // 输出到控制台
    if (m_consoleOutput) {
        // 在控制台输出时添加颜色
        QString consoleMessage = logLevelToColor(level) + formattedMessage + "\033[0m";
        qDebug().noquote() << consoleMessage;
    }

    // 如果是致命错误，可以在这里添加程序退出逻辑
    if (level == Fatal) {
        // qApp->exit(1);
    }
}

QString Logger::formatLogMessage(LogLevel level, const QString &message,
                                 const char *file, int line)
{
    // 格式化时间
    QString timeStr = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz");

    // 构建日志内容
    QString logMessage =
        QString("[%1] [%2] ").arg(timeStr).arg(logLevelToString(level));

    // 添加文件名和行号(如果提供)
    if (file && line > 0) {
        QString fileName =
            QFileInfo(QString(file)).fileName(); // 只保留文件名，去掉路径
        logMessage += QString("[%1:%2] ").arg(fileName).arg(line);
    }

    // 添加日志消息
    logMessage += message;

    return logMessage;
}

QString Logger::logLevelToString(LogLevel level)
{
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

QString Logger::logLevelToColor(LogLevel level)
{
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
