#include "ui/jx/JxMainWindow.h"

const QString JxMainWindow::QSS = R"(
JxMainWindow {
  background-color: none;
}
)";

JxMainWindow::JxMainWindow(JxWidget *parent) : QMainWindow(parent) { initUI(); }

void JxMainWindow::initUI() { this->setStyleSheet(QSS); }
