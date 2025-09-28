#ifndef _JXVBOXLAYOUT_H_
#define _JXVBOXLAYOUT_H_

#include "ui/jx/JxWidget.h"
#include <QVBoxLayout>

class JxVBoxLayout : public QVBoxLayout {
  Q_OBJECT
public:
  explicit JxVBoxLayout(JxWidget *parent = nullptr);

private:
  void initUI();
};

#endif /* End of _JXVBOXLAYOUT_H_ */
