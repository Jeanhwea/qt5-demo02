#include "ui/jx/JxPushButton.h"

#include "ui/jx/JxWidget.h"

const QString JxPushButton::QSS = R"(
JxPushButton {
  background-color: none;
}
)";

JxPushButton::JxPushButton(JxWidget *parent) : QPushButton(parent) { initUI(); }

void JxPushButton::initUI() { this->setStyleSheet(QSS); }
