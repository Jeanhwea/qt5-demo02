#include "util.h"

#include <QDateTime>

long long Util::getCurrentTimestamp() {
  return QDateTime::currentDateTime().toMSecsSinceEpoch();
}
