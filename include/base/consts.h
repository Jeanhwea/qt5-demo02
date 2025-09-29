#ifndef _CONSTS_H_
#define _CONSTS_H_

#include <QString>

namespace Color {
const QString WHITE = "\033[37m";
const QString GREEN = "\033[32m";
const QString YELLOW = "\033[33m";
const QString RED = "\033[31m";
const QString BRIGHT_RED = "\033[1;31m";
const QString DEFAULT = "\033[0m";
}; // namespace Color

namespace ErrorCode {
const int Success = 0;
const int InitError = 1;
const int Panic = 2;
}; // namespace ErrorCode

#endif /* End of _CONSTS_H_ */
