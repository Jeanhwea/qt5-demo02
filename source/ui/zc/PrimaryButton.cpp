#include "ui/zc/PrimaryButton.h"

#include "ui/zc/Theme.h"

const QString PrimaryButton::QSS = theme::replaceVariables(R"(
PrimaryButton {
  color: VAR_COLOR_A_800;
  background-color: VAR_COLOR_A_100;
  min-height: 28px;
  border-radius: 4px;
  border: 1px solid VAR_COLOR_A_500;
})");

PrimaryButton::PrimaryButton(JxWidget *parent) : JxPushButton(parent) {
  initUI();
}

void PrimaryButton::initUI() { this->setStyleSheet(QSS); }
