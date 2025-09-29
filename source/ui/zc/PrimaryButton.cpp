#include "ui/zc/PrimaryButton.h"

#include "ui/zc/ThemeColor.h"

const QString PrimaryButton::QSS =
    QString(R"(
PrimaryButton {
  color: %1;
  background-color: %2;
  height: 30px;
  border-radius: 4px;
  border: 1px solid %3;
})")
        .arg(ThemeColor::PRIMARY_COLOR_800, ThemeColor::PRIMARY_COLOR_100,
             ThemeColor::PRIMARY_COLOR_800);

PrimaryButton::PrimaryButton(JxWidget *parent) : JxPushButton(parent) {
  initUI();
}

void PrimaryButton::initUI() { this->setStyleSheet(QSS); }
