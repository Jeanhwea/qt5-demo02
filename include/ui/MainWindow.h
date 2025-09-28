#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "ui/jx/JxVBoxLayout.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUI();
    void onBtnClick();

    QWidget *widget;
    JxVBoxLayout *layout;
};

#endif /* End of _MAINWINDOW_H_ */
