#ifndef _JXLABEL_H_
#define _JXLABEL_H_

#include "ui/jx/JxWidget.h"

#include <QLabel>

class JxLabel : public QLabel {
  Q_OBJECT

public:
  explicit JxLabel(JxWidget *parent = nullptr);

private:
  void initUI();

  static const QString QSS;
};

#endif /* End of _JXLABEL_H_ */
