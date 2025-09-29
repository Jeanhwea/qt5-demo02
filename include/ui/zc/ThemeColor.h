#ifndef _THEMECOLOR_H_
#define _THEMECOLOR_H_

#include <QString>

namespace ThemeColor {
const QString PRIMARY_COLOR_050 = "#E3F2FD";
const QString PRIMARY_COLOR_100 = "#BBDEFB";
const QString PRIMARY_COLOR_200 = "#90CAF9";
const QString PRIMARY_COLOR_300 = "#64B5F6";
const QString PRIMARY_COLOR_400 = "#42A5F5";
const QString PRIMARY_COLOR_500 = "#2196F3";
const QString PRIMARY_COLOR_600 = "#1E88E5";
const QString PRIMARY_COLOR_700 = "#1976D2";
const QString PRIMARY_COLOR_800 = "#1565C0";
const QString PRIMARY_COLOR_900 = "#0D47A1";


   // 生成颜色替换映射表
const QHash<QString, QString> colorMap = {
    {"PRIMARY_COLOR_050", PRIMARY_COLOR_050},
    {"PRIMARY_COLOR_100", PRIMARY_COLOR_100},
    {"PRIMARY_COLOR_200", PRIMARY_COLOR_200},
    {"PRIMARY_COLOR_300", PRIMARY_COLOR_300},
    {"PRIMARY_COLOR_400", PRIMARY_COLOR_400},
    {"PRIMARY_COLOR_500", PRIMARY_COLOR_500},
    {"PRIMARY_COLOR_600", PRIMARY_COLOR_600},
    {"PRIMARY_COLOR_700", PRIMARY_COLOR_700},
    {"PRIMARY_COLOR_800", PRIMARY_COLOR_800},
    {"PRIMARY_COLOR_900", PRIMARY_COLOR_900}};

// 替换QSS中的颜色常量
static QString replaceColors(const QString &qss) {
  QString result = qss;
  for (auto it = colorMap.constBegin(); it != colorMap.constEnd(); ++it) {
    result.replace(it.key(), it.value());
  }
  return result;
}
}; // namespace ThemeColor

#endif /* End of _THEMECOLOR_H_ */
