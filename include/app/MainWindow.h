#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "ui/jx/JxMainWindow.h"
#include "ui/jx/JxVBoxLayout.h"
#include "ui/jx/JxWidget.h"

#include <QString>

class MainWindow : public JxMainWindow {
  Q_OBJECT

public:
  MainWindow(JxWidget *parent = nullptr);
  ~MainWindow();

private:
  void initUI();
  void onBtnClick();
  void onBtnClick02();

  static const QString QSS;

  JxWidget m_widget;
  JxVBoxLayout m_layout;
};

#endif /* End of _MAINWINDOW_H_ */
