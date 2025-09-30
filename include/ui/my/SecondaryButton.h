#ifndef _SECONDARYBUTTON_H_
#define _SECONDARYBUTTON_H_

#include "ui/jx/JxPushButton.h"

class SecondaryButton : public JxPushButton {
  Q_OBJECT

public:
  explicit SecondaryButton(JxWidget *parent = nullptr);

private:
  void initUI();

  static const QString QSS;
};

#endif /* End of _SECONDARYBUTTON_H_ */
