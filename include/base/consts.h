#ifndef _CONSTS_H_
#define _CONSTS_H_

#include <QString>

namespace colors {
inline constexpr const char *WHITE = "\033[37m";
inline constexpr const char *GREEN = "\033[32m";
inline constexpr const char *YELLOW = "\033[33m";
inline constexpr const char *RED = "\033[31m";
inline constexpr const char *BRIGHT_RED = "\033[1;31m";
inline constexpr const char *DEFAULT = "\033[0m";
}; // namespace colors

namespace errcode {
inline constexpr int SUCCESS = 0;
inline constexpr int INIT_ERROR = 1;
inline constexpr int PANIC = 2;
}; // namespace errcode

#endif /* End of _CONSTS_H_ */
