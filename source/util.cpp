#include "util.h"

#include <qdatetime.h>

long long Util::getCurrentTimestamp() {
  return QDateTime::currentDateTime().toMSecsSinceEpoch();
}
