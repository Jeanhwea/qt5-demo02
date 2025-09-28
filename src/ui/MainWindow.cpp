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
}

void MainWindow::initUI()
{
    this->widget = new QWidget(this);
    JxVBoxLayout *layout = new JxVBoxLayout();

    JxPushButton *btn = new JxPushButton(this);
    btn->setText("Click Me");
    btn->connect(btn, &JxPushButton::clicked, this, &MainWindow::onBtnClick);
    layout->addWidget(btn);

    layout->addStretch();

    this->layout = layout;
    this->setCentralWidget(this->widget);
}

void MainWindow::onBtnClick()
{
    qDebug() << "Button Clicked!" << Util::getCurrentTimestamp();
}
