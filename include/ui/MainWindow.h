#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
  void onBtnClick();
  void onBtnClick2();

  JxWidget m_widget;
  JxVBoxLayout m_layout;
};

#endif /* End of _MAINWINDOW_H_ */
