#include "app/MainWindow.h"

#include "base/logger.h"
#include "base/util.h"
#include "ui/jx/JxHBoxLayout.h"
#include "ui/jx/JxLabel.h"
#include "ui/my/PrimaryButton.h"
#include "ui/my/SecondaryButton.h"
#include "ui/my/Theme.h"

const QString MainWindow::QSS = Theme::instance().replace(R"(
MainWindow {
  background-color: SYM_COLOR_WHITE;
}

MainWindow * {
  font-size: 16px;
}

MainWindow JxLabel {
  color: SYM_COLOR_A_500;
  font-weight: bold;
  qproperty-alignment: 'AlignCenter';
}
)");

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

  JxHBoxLayout *ctn01 = new JxHBoxLayout();

  PrimaryButton *btn01 = new PrimaryButton(&m_widget);
  btn01->setText("Click Me");
  btn01->connect(btn01, &PrimaryButton::clicked, this, &MainWindow::onBtnClick01);
  ctn01->addWidget(btn01);

  SecondaryButton *btn02 = new SecondaryButton(&m_widget);
  btn02->setText("Click Me 2");
  btn02->connect(btn02, &SecondaryButton::clicked, this, &MainWindow::onBtnClick02);
  ctn01->addWidget(btn02);
  ctn01->addStretch();

  m_layout.addLayout(ctn01);
  m_layout.addStretch();

  this->setCentralWidget(&m_widget);
}

void MainWindow::onBtnClick01() {
  LOG_I(QString("Button clicked at %1").arg(util::getCurrentTimestamp()));
}

void MainWindow::onBtnClick02() {
  LOG_D(QString("Button clicked at %1").arg(util::getCurrentTimestamp()));
}
