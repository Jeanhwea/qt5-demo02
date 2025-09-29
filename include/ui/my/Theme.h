#ifndef _THEMECOLOR_H_
#define _THEMECOLOR_H_

#include <QHash>
#include <QString>

namespace theme {

// Primary Colors: Bule
constexpr const char *SYSTEM_COLOR_A_050 = "#E3F2FD";
constexpr const char *SYSTEM_COLOR_A_100 = "#BBDEFB";
constexpr const char *SYSTEM_COLOR_A_200 = "#90CAF9";
constexpr const char *SYSTEM_COLOR_A_300 = "#64B5F6";
constexpr const char *SYSTEM_COLOR_A_400 = "#42A5F5";
constexpr const char *SYSTEM_COLOR_A_500 = "#2196F3";
constexpr const char *SYSTEM_COLOR_A_600 = "#1E88E5";
constexpr const char *SYSTEM_COLOR_A_700 = "#1976D2";
constexpr const char *SYSTEM_COLOR_A_800 = "#1565C0";
constexpr const char *SYSTEM_COLOR_A_900 = "#0D47A1";
// Second Colors: Green
constexpr const char *SYSTEM_COLOR_B_050 = "#E0F2F1";
constexpr const char *SYSTEM_COLOR_B_100 = "#B2DFDB";
constexpr const char *SYSTEM_COLOR_B_200 = "#80CBC4";
constexpr const char *SYSTEM_COLOR_B_300 = "#4DB6AC";
constexpr const char *SYSTEM_COLOR_B_400 = "#26A69A";
constexpr const char *SYSTEM_COLOR_B_500 = "#009688";
constexpr const char *SYSTEM_COLOR_B_600 = "#00897B";
constexpr const char *SYSTEM_COLOR_B_700 = "#00796B";
constexpr const char *SYSTEM_COLOR_B_800 = "#00695C";
constexpr const char *SYSTEM_COLOR_B_900 = "#004D40";
// Common Colors: Green
constexpr const char *SYSTEM_COLOR_BLACK = "#000000";
constexpr const char *SYSTEM_COLOR_WHITE = "#FFFFFF";

const static QHash<QString, QString> symbolMap = {
    {"SYM_COLOR_A_050", SYSTEM_COLOR_A_050},
    {"SYM_COLOR_A_100", SYSTEM_COLOR_A_100},
    {"SYM_COLOR_A_200", SYSTEM_COLOR_A_200},
    {"SYM_COLOR_A_300", SYSTEM_COLOR_A_300},
    {"SYM_COLOR_A_400", SYSTEM_COLOR_A_400},
    {"SYM_COLOR_A_500", SYSTEM_COLOR_A_500},
    {"SYM_COLOR_A_600", SYSTEM_COLOR_A_600},
    {"SYM_COLOR_A_700", SYSTEM_COLOR_A_700},
    {"SYM_COLOR_A_800", SYSTEM_COLOR_A_800},
    {"SYM_COLOR_A_900", SYSTEM_COLOR_A_900},
    {"SYM_COLOR_B_050", SYSTEM_COLOR_B_050},
    {"SYM_COLOR_B_100", SYSTEM_COLOR_B_100},
    {"SYM_COLOR_B_200", SYSTEM_COLOR_B_200},
    {"SYM_COLOR_B_300", SYSTEM_COLOR_B_300},
    {"SYM_COLOR_B_400", SYSTEM_COLOR_B_400},
    {"SYM_COLOR_B_500", SYSTEM_COLOR_B_500},
    {"SYM_COLOR_B_600", SYSTEM_COLOR_B_600},
    {"SYM_COLOR_B_700", SYSTEM_COLOR_B_700},
    {"SYM_COLOR_B_800", SYSTEM_COLOR_B_800},
    {"SYM_COLOR_B_900", SYSTEM_COLOR_B_900},
    {"SYM_COLOR_BLACK", SYSTEM_COLOR_BLACK},
    {"SYM_COLOR_WHITE", SYSTEM_COLOR_WHITE},
};

inline QString replaceVariables(const QString &qss) {
  QString result = qss;
  for (auto it = symbolMap.constBegin(); it != symbolMap.constEnd(); ++it) {
    result.replace(it.key(), it.value());
  }
  return result;
}

} // namespace theme

#endif /* End of _THEMECOLOR_H_ */
