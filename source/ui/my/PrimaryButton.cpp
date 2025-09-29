#include "ui/my/PrimaryButton.h"

#include "ui/my/Theme.h"

const QString PrimaryButton::QSS = Theme::instance().replace(R"(
PrimaryButton {
  color: SYM_COLOR_A_800;
  background-color: SYM_COLOR_A_050;
  min-height: 28px;
  min-width: 100px;
  border-radius: 4px;
  border: 1px solid SYM_COLOR_A_500;
}
PrimaryButton::hover {
  background-color: SYM_COLOR_A_100;
}
)");

PrimaryButton::PrimaryButton(JxWidget *parent) : JxPushButton(parent) { initUI(); }

void PrimaryButton::initUI() { this->setStyleSheet(QSS); }
