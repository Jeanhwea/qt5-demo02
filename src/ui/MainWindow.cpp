#include "ui/MainWindow.h"
#include <QDebug>
#include <QLabel>
#include "components.h"
#include "util.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // 初始化主窗口
    this->setWindowTitle("Demo02 - " + QString::number(Util::getCurrentTimestamp()));
    this->setGeometry(100, 100, 800, 600);

    // 初始化UI组件
    this->initUI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initUI()
{
    JxPushButton *btn = new JxPushButton(this);
    btn->setText("Click Me");
    btn->connect(btn, &JxPushButton::clicked, this, &MainWindow::onBtnClick);

    this->setCentralWidget(btn);
}

void MainWindow::onBtnClick()
{
    qDebug() << "Button Clicked!" << Util::getCurrentTimestamp();
}
