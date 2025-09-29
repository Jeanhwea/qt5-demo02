#ifndef _THEMECOLOR_H_
#define _THEMECOLOR_H_

#include <QHash>
#include <QString>

class Theme {
public:
  static Theme &instance();
  QString replaceSymbols(const QString &input) const;

private:
  Theme();
  Theme(const Theme &) = delete;
  Theme &operator=(const Theme &) = delete;

  QHash<QString, QString> m_symbols;
};

#endif /* End of _THEMECOLOR_H_ */
