#include "ui/MainWindow.h"

#include "logger.h"
#include "ui/jx/JxLabel.h"
#include "ui/zc/PrimaryButton.h"
#include "util.h"

const QString MainWindow::QSS = R"(
MainWindow {
  background-color: none;
}

MainWindow * {
  font-size: 14px;
}

MainWindow JxLabel {
  qproperty-alignment: 'AlignCenter';
}
)";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_widget(this), m_layout(&m_widget) {
  this->setStyleSheet(QSS);
  initUI();
}

MainWindow::~MainWindow() {}

void MainWindow::initUI() {
  this->setWindowTitle("DEMO");
  this->setGeometry(100, 100, 800, 600);
  this->setContentsMargins(0, 0, 0, 0);

  m_layout.setContentsMargins(5, 5, 5, 5);

  JxLabel *text01 = new JxLabel(&m_widget);
  text01->setText("示例程序002");
  // text01->setAlignment(Qt::AlignCenter);
  m_layout.addWidget(text01);

  PrimaryButton *btn01 = new PrimaryButton(&m_widget);
  btn01->setText("Click Me");
  btn01->connect(btn01, &PrimaryButton::clicked, this, &MainWindow::onBtnClick);
  m_layout.addWidget(btn01);

  PrimaryButton *btn02 = new PrimaryButton(&m_widget);
  btn02->setText("Click Me 2");
  btn02->connect(btn02, &PrimaryButton::clicked, this,
                 &MainWindow::onBtnClick02);
  m_layout.addWidget(btn02);

  m_layout.addStretch();

  m_widget.setLayout(&m_layout);
  this->setCentralWidget(&m_widget);
}

void MainWindow::onBtnClick() {
  LOG_D(QString("Button clicked at %1").arg(util::getCurrentTimestamp()));
}

void MainWindow::onBtnClick02() {
  LOG_I(QString("Button clicked at %1").arg(util::getCurrentTimestamp()));
}
