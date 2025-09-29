#ifndef _JXPUSHBUTTON_H_
#define _JXPUSHBUTTON_H_

#include "ui/jx/JxWidget.h"

#include <QPushButton>

class JxPushButton : public QPushButton {
  Q_OBJECT
public:
  explicit JxPushButton(JxWidget *parent = nullptr);

private:
  void initUI();

  static const QString QSS;
};

#endif /* End of _JXPUSHBUTTON_H_ */
