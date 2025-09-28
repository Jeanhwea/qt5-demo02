#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <QString>

class Util
{
public:
    // 获取当前时间戳（秒级）
    static long long getCurrentTimestamp();

    static void info(const QString &msg);
};

#endif /* End of _UTILITIES_H_ */
