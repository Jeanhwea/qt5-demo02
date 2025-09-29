#include "ui/zc/PrimaryButton.h"

const QString PrimaryButton::QSS = R"(
PrimaryButton {
  background-color: none;
}
)";

PrimaryButton::PrimaryButton(JxWidget *parent) : JxPushButton(parent) {
  initUI();
}

void PrimaryButton::initUI() { this->setStyleSheet(QSS); }
