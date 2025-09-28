#include "ui/MainWindow.h"
#include <QDebug>
#include <QLabel>
#include "components.h"
#include "logger.h"
#include "util.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // 初始化主窗口
    this->setWindowTitle("DEMO");
    this->setGeometry(100, 100, 800, 600);
    this->setContentsMargins(0, 0, 0, 0);

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
    // layout->setContentsMargins(100, 100, 100, 100);

    JxPushButton *btn01 = new JxPushButton(widget);
    btn01->setText("Click Me");
    btn01->connect(btn01, &JxPushButton::clicked, this, &MainWindow::onBtnClick);
    layout->addWidget(btn01);

    JxPushButton *btn02 = new JxPushButton(widget);
    btn02->setText("Click Me 2");
    // btn02->connect(btn02, &JxPushButton::clicked, this, &MainWindow::onBtnClick);
    layout->addWidget(btn02);

    layout->addStretch();

    this->widget = widget;
    widget->setLayout(layout);
    this->layout = layout;
    this->setCentralWidget(this->widget);
}

void MainWindow::onBtnClick()
{
    LOG_DEBUG(QString("Button clicked at %1").arg(Util::getCurrentTimestamp()));
}
