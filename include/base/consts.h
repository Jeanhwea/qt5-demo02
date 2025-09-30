#ifndef _CONSTS_H_
#define _CONSTS_H_

#include <QString>

namespace colors {
static const QString WHITE = "\033[37m";
static const QString GREEN = "\033[32m";
static const QString YELLOW = "\033[33m";
static const QString RED = "\033[31m";
static const QString BRIGHT_RED = "\033[1;31m";
static const QString DEFAULT = "\033[0m";
}; // namespace colors

namespace errcode {
static const int SUCCESS = 0;
static const int INIT_ERROR = 1;
static const int PANIC = 2;
}; // namespace errcode

#endif /* End of _CONSTS_H_ */
