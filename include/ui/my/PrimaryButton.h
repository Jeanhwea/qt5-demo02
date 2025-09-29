#ifndef _PRIMARYBUTTON_H_
#define _PRIMARYBUTTON_H_

#include "ui/jx/JxPushButton.h"

class PrimaryButton : public JxPushButton {
  Q_OBJECT
public:
  explicit PrimaryButton(JxWidget *parent = nullptr);

private:
  void initUI();

  static const QString QSS;
};

#endif /* End of _PRIMARYBUTTON_H_ */
