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
  // Primary Colors: Bule
  m_symbols.insert("SYM_COLOR_A_050", "#E3F2FD");
  m_symbols.insert("SYM_COLOR_A_100", "#BBDEFB");
  m_symbols.insert("SYM_COLOR_A_200", "#90CAF9");
  m_symbols.insert("SYM_COLOR_A_300", "#64B5F6");
  m_symbols.insert("SYM_COLOR_A_400", "#42A5F5");
  m_symbols.insert("SYM_COLOR_A_500", "#2196F3");
  m_symbols.insert("SYM_COLOR_A_600", "#1E88E5");
  m_symbols.insert("SYM_COLOR_A_700", "#1976D2");
  m_symbols.insert("SYM_COLOR_A_800", "#1565C0");
  m_symbols.insert("SYM_COLOR_A_900", "#0D47A1");
  // Secondary Colors: Green
  m_symbols.insert("SYM_COLOR_B_050", "#E0F2F1");
  m_symbols.insert("SYM_COLOR_B_100", "#B2DFDB");
  m_symbols.insert("SYM_COLOR_B_200", "#80CBC4");
  m_symbols.insert("SYM_COLOR_B_300", "#4DB6AC");
  m_symbols.insert("SYM_COLOR_B_400", "#26A69A");
  m_symbols.insert("SYM_COLOR_B_500", "#009688");
  m_symbols.insert("SYM_COLOR_B_600", "#00897B");
  m_symbols.insert("SYM_COLOR_B_700", "#00796B");
  m_symbols.insert("SYM_COLOR_B_800", "#00695C");
  m_symbols.insert("SYM_COLOR_B_900", "#004D40");
  // Disabled Colors: Gray
  m_symbols.insert("SYM_COLOR_Z_050", "#FAFAFA");
  m_symbols.insert("SYM_COLOR_Z_100", "#F5F5F5");
  m_symbols.insert("SYM_COLOR_Z_200", "#EEEEEE");
  m_symbols.insert("SYM_COLOR_Z_300", "#E0E0E0");
  m_symbols.insert("SYM_COLOR_Z_400", "#BDBDBD");
  m_symbols.insert("SYM_COLOR_Z_500", "#9E9E9E");
  m_symbols.insert("SYM_COLOR_Z_600", "#757575");
  m_symbols.insert("SYM_COLOR_Z_700", "#616161");
  m_symbols.insert("SYM_COLOR_Z_800", "#424242");
  m_symbols.insert("SYM_COLOR_Z_900", "#212121");
  // Common Colors: Black & White
  m_symbols.insert("SYM_COLOR_BLACK", "#000000");
  m_symbols.insert("SYM_COLOR_WHITE", "#FFFFFF");
}
