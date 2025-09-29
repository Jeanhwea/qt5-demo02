#ifndef _THEMECOLOR_H_
#define _THEMECOLOR_H_

#include <QHash>
#include <QString>

namespace theme {
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

const static QHash<QString, QString> variableMap = {
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

inline QString replaceVariables(const QString &qss) {
  QString result = qss;
  for (auto it = variableMap.constBegin(); it != variableMap.constEnd(); ++it) {
    result.replace(it.key(), it.value());
  }
  return result;
}

} // namespace theme

#endif /* End of _THEMECOLOR_H_ */
