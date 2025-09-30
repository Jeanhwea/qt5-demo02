#ifndef _JXMAINWINDOW_H_
#define _JXMAINWINDOW_H_

#include "ui/jx/JxWidget.h"

#include <QMainWindow>

class JxMainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit JxMainWindow(JxWidget *parent = nullptr);

private:
  void initUI();

  static const QString QSS;
};

#endif /* End of _JXMAINWINDOW_H_ */
