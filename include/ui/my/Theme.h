#ifndef _THEMECOLOR_H_
#define _THEMECOLOR_H_

#include <QHash>
#include <QMutex>
#include <QMutexLocker>
#include <QScopedPointer>
#include <QString>

class Theme {
public:
  static Theme &instance() {
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    static QScopedPointer<Theme> inst(new Theme());
    return *inst.data();
  }

  QString replaceSymbols(const QString &input) const {
    QString result = input;
    for (const auto &key : m_symbols.keys()) {
      result.replace(key, m_symbols.value(key));
    }
    return result;
  }

private:
  Theme() {
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
    // Second Colors: Green
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
    // Common Colors: Green
    m_symbols.insert("SYM_COLOR_BLACK", "#000000");
    m_symbols.insert("SYM_COLOR_WHITE", "#FFFFFF");
  }

  Theme(const Theme &) = delete;
  Theme &operator=(const Theme &) = delete;

  QHash<QString, QString> m_symbols;
};

#endif /* End of _THEMECOLOR_H_ */
