#include "ui/jx/JxWidget.h"

const QString JxWidget::QSS = R"(
JxWidget {
  background-color: none;
}
)";

JxWidget::JxWidget(QWidget *parent) : QWidget(parent) {
  this->setStyleSheet(QSS);
}
