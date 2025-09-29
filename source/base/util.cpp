#include "base/util.h"

#include <QDateTime>

namespace util {
long long getCurrentTimestamp() { return QDateTime::currentDateTime().toMSecsSinceEpoch(); }
} // namespace util
