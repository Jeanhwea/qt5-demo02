#ifndef JXPUSHBUTTON_H
#define JXPUSHBUTTON_H

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

#endif // JXPUSHBUTTON_H
