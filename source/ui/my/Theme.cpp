#include "ui/my/Theme.h"

#include <QMutex>
#include <QMutexLocker>
#include <QScopedPointer>

Theme &Theme::instance() {
  static QMutex mutex;
  QMutexLocker locker(&mutex);
  static QScopedPointer<Theme> inst(new Theme());
  return *inst.data();
}

QString Theme::replace(const QString &input) const {
  QString result = input;
  for (const auto &key : m_symbols.keys()) {
    result.replace(key, m_symbols.value(key));
  }
  return result;
}

Theme::Theme() {
  const QList<QPair<QString, QString>> colorPairs = {
      // Primary Colors: Blue
      {"SYM_COLOR_A_050", "#E3F2FD"},
      {"SYM_COLOR_A_100", "#BBDEFB"},
      {"SYM_COLOR_A_200", "#90CAF9"},
      {"SYM_COLOR_A_300", "#64B5F6"},
      {"SYM_COLOR_A_400", "#42A5F5"},
      {"SYM_COLOR_A_500", "#2196F3"},
      {"SYM_COLOR_A_600", "#1E88E5"},
      {"SYM_COLOR_A_700", "#1976D2"},
      {"SYM_COLOR_A_800", "#1565C0"},
      {"SYM_COLOR_A_900", "#0D47A1"},
      // Secondary Colors: Green
      {"SYM_COLOR_B_050", "#E0F2F1"},
      {"SYM_COLOR_B_100", "#B2DFDB"},
      {"SYM_COLOR_B_200", "#80CBC4"},
      {"SYM_COLOR_B_300", "#4DB6AC"},
      {"SYM_COLOR_B_400", "#26A69A"},
      {"SYM_COLOR_B_500", "#009688"},
      {"SYM_COLOR_B_600", "#00897B"},
      {"SYM_COLOR_B_700", "#00796B"},
      {"SYM_COLOR_B_800", "#00695C"},
      {"SYM_COLOR_B_900", "#004D40"},
      // Disabled Colors: Gray
      {"SYM_COLOR_Z_050", "#FAFAFA"},
      {"SYM_COLOR_Z_100", "#F5F5F5"},
      {"SYM_COLOR_Z_200", "#EEEEEE"},
      {"SYM_COLOR_Z_300", "#E0E0E0"},
      {"SYM_COLOR_Z_400", "#BDBDBD"},
      {"SYM_COLOR_Z_500", "#9E9E9E"},
      {"SYM_COLOR_Z_600", "#757575"},
      {"SYM_COLOR_Z_700", "#616161"},
      {"SYM_COLOR_Z_800", "#424242"},
      {"SYM_COLOR_Z_900", "#212121"},
      // Common Colors: Black & White
      {"SYM_COLOR_BLACK", "#000000"},
      {"SYM_COLOR_WHITE", "#FFFFFF"},
  };

  for (const auto &pair : colorPairs) {
    m_symbols.insert(pair.first, pair.second);
  }
}
