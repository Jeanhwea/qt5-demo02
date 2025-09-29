#include "ui/zc/PrimaryButton.h"

#include "ui/zc/Theme.h"

const QString PrimaryButton::QSS = theme::replaceColors(R"(
PrimaryButton {
  color: PRIMARY_COLOR_800;
  background-color: PRIMARY_COLOR_100;
  min-height: 28px;
  border-radius: 4px;
  border: 1px solid PRIMARY_COLOR_500;
})");

PrimaryButton::PrimaryButton(JxWidget *parent) : JxPushButton(parent) {
  initUI();
}

void PrimaryButton::initUI() { this->setStyleSheet(QSS); }
