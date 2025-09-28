#include "util.h"
#include <QDebug>
#include <chrono>

long long Util::getCurrentTimestamp()
{
    auto now = std::chrono::system_clock::now();

    auto duration = now.time_since_epoch();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);

    return seconds.count();
}

void Util::info(const QString &msg)
{
    qDebug() << msg;
}
