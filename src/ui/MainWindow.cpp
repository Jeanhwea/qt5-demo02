#include "ui/MainWindow.h"
#include <QDebug>
#include <QLabel>
#include "components.h"
#include "util.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // 初始化主窗口
    this->setWindowTitle("DEMO");
    this->setGeometry(100, 100, 800, 600);

    // 初始化UI组件
    this->initUI();
}

MainWindow::~MainWindow()
{
    delete this->layout;
    delete this->widget;
}

void MainWindow::initUI()
{
    widget = new JxWidget(this);
    JxVBoxLayout *layout = new JxVBoxLayout();

    JxPushButton *btn01 = new JxPushButton(widget);
    btn01->setText("Click Me");
    btn01->connect(btn01, &JxPushButton::clicked, this, &MainWindow::onBtnClick);
    layout->addWidget(btn01);

    layout->addStretch();

    this->widget = widget;
    this->layout = layout;
    this->setCentralWidget(this->widget);
}

void MainWindow::onBtnClick()
{
    qDebug() << "Button Clicked!" << Util::getCurrentTimestamp();
}
