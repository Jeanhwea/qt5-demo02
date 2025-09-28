#include "ui/MainWindow.h"
#include <QDebug>
#include <QLabel>
#include "components.h"
#include "logger.h"
#include "util.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    
    this->widget = new JxWidget(this);
    this->layout = new JxVBoxLayout(this->widget);


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
    // 初始化主窗口
    this->setWindowTitle("DEMO");
    this->setGeometry(100, 100, 800, 600);
    this->setContentsMargins(0, 0, 0, 0);

    layout = this->layout;

    layout->setContentsMargins(5, 5, 5, 5);

    JxPushButton *btn01 = new JxPushButton(widget);
    btn01->setText("Click Me");
    btn01->connect(btn01, &JxPushButton::clicked, this, &MainWindow::onBtnClick);
    layout->addWidget(btn01);

    JxPushButton *btn02 = new JxPushButton(widget);
    btn02->setText("Click Me 2");
    btn02->connect(btn02, &JxPushButton::clicked, this, &MainWindow::onBtnClick2);
    layout->addWidget(btn02);

    layout->addStretch();

    widget->setLayout(layout);
    this->layout = layout;
    this->setCentralWidget(this->widget);
}

void MainWindow::onBtnClick()
{
    LOG_DEBUG(QString("Button clicked at %1").arg(Util::getCurrentTimestamp()));
}

void MainWindow::onBtnClick2()
{
    LOG_INFO(QString("Button clicked at %1").arg(Util::getCurrentTimestamp()));
}
