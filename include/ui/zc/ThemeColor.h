#ifndef _THEMECOLOR_H_
#define _THEMECOLOR_H_

#include <QHash>
#include <QString>

namespace ThemeColor {
constexpr const char *PRIMARY_COLOR_050 = "#E3F2FD";
constexpr const char *PRIMARY_COLOR_100 = "#BBDEFB";
constexpr const char *PRIMARY_COLOR_200 = "#90CAF9";
constexpr const char *PRIMARY_COLOR_300 = "#64B5F6";
constexpr const char *PRIMARY_COLOR_400 = "#42A5F5";
constexpr const char *PRIMARY_COLOR_500 = "#2196F3";
constexpr const char *PRIMARY_COLOR_600 = "#1E88E5";
constexpr const char *PRIMARY_COLOR_700 = "#1976D2";
constexpr const char *PRIMARY_COLOR_800 = "#1565C0";
constexpr const char *PRIMARY_COLOR_900 = "#0D47A1";

inline const QHash<QString, QString> colorMap = {
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

enum class ColorLevel {
  LEVEL_050,
  LEVEL_100,
  LEVEL_200,
  LEVEL_300,
  LEVEL_400,
  LEVEL_500,
  LEVEL_600,
  LEVEL_700,
  LEVEL_800,
  LEVEL_900
};

inline QString getColor(ColorLevel level) {
  switch (level) {
  case ColorLevel::LEVEL_050:
    return PRIMARY_COLOR_050;
  case ColorLevel::LEVEL_100:
    return PRIMARY_COLOR_100;
  case ColorLevel::LEVEL_200:
    return PRIMARY_COLOR_200;
  case ColorLevel::LEVEL_300:
    return PRIMARY_COLOR_300;
  case ColorLevel::LEVEL_400:
    return PRIMARY_COLOR_400;
  case ColorLevel::LEVEL_500:
    return PRIMARY_COLOR_500;
  case ColorLevel::LEVEL_600:
    return PRIMARY_COLOR_600;
  case ColorLevel::LEVEL_700:
    return PRIMARY_COLOR_700;
  case ColorLevel::LEVEL_800:
    return PRIMARY_COLOR_800;
  case ColorLevel::LEVEL_900:
    return PRIMARY_COLOR_900;
  default:
    return PRIMARY_COLOR_500;
  }
}

inline QString replaceColors(const QString &qss) {
  QString result = qss;
  for (const auto &[key, value] : colorMap.asKeyValueRange()) {
    result.replace(key, value);
  }
  return result;
}

} // namespace ThemeColor

#endif /* End of _THEMECOLOR_H_ */
