#include "ui/zc/ThemeColor.h"

namespace ThemeColor {

QString replaceColors(const QString &qss) {
  QString result = qss;
  for (auto it = colorMap.constBegin(); it != colorMap.constEnd(); ++it) {
    result.replace(it.key(), it.value());
  }
  return result;
}

} // namespace ThemeColor
