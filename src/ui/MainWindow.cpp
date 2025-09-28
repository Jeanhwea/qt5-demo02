#include "ui/MainWindow.h"
#include <QLabel>
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
    // 初始化UI组件
    QLabel *label = new QLabel(this);
    label->setText("Hello, World!");
    label->setGeometry(100, 100, 200, 50);
}
