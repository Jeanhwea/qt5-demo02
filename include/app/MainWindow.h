#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "ui/jx/JxVBoxLayout.h"
#include "ui/jx/JxWidget.h"

#include <QMainWindow>
#include <QString>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  void initUI();
  void onBtnClick01();
  void onBtnClick02();

  static const QString QSS;

  JxWidget m_widget;
  JxVBoxLayout m_layout;
};

#endif /* End of _MAINWINDOW_H_ */
