#ifndef _JXHBOXLAYOUT_H_
#define _JXHBOXLAYOUT_H_

#include <QHBoxLayout>

#include "ui/jx/JxWidget.h"

class JxHBoxLayout : public QHBoxLayout {
  Q_OBJECT
public:
  explicit JxHBoxLayout(JxWidget *parent = nullptr);

private:
  void initUI();
};

#endif /* End of _JXHBOXLAYOUT_H_ */
