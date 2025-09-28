#include "ui/MainWindow.h"
#include <QDebug>
#include <QLabel>
#include "components.h"
#include "logger.h"
#include "util.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_widget = new JxWidget(this);

    m_layout = new JxVBoxLayout(this->m_widget);

    initUI();
}

MainWindow::~MainWindow()
{
    delete m_layout;
    delete m_widget;
}

void MainWindow::initUI()
{
    // 初始化主窗口
    this->setWindowTitle("DEMO");
    this->setGeometry(100, 100, 800, 600);
    this->setContentsMargins(0, 0, 0, 0);

    m_layout->setContentsMargins(5, 5, 5, 5);

    JxPushButton *btn01 = new JxPushButton(m_widget);
    btn01->setText("Click Me");
    btn01->connect(btn01, &JxPushButton::clicked, this, &MainWindow::onBtnClick);
    m_layout->addWidget(btn01);

    JxPushButton *btn02 = new JxPushButton(m_widget);
    btn02->setText("Click Me 2");
    btn02->connect(btn02, &JxPushButton::clicked, this, &MainWindow::onBtnClick2);
    m_layout->addWidget(btn02);

    m_layout->addStretch();

    m_widget->setLayout(m_layout);
    this->setCentralWidget(m_widget);
}

void MainWindow::onBtnClick()
{
    LOG_DEBUG(QString("Button clicked at %1").arg(Util::getCurrentTimestamp()));
}

void MainWindow::onBtnClick2()
{
    LOG_INFO(QString("Button clicked at %1").arg(Util::getCurrentTimestamp()));
}
