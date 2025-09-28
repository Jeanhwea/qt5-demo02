#ifndef _JXHBOXLAYOUT_H_
#define _JXHBOXLAYOUT_H_

#include "ui/jx/JxWidget.h"

#include <QHBoxLayout>

class JxHBoxLayout : public QHBoxLayout {
  Q_OBJECT
public:
  explicit JxHBoxLayout(JxWidget *parent = nullptr);

private:
  void initUI();
};

#endif /* End of _JXHBOXLAYOUT_H_ */
