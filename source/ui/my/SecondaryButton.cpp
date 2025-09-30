#include "ui/my/SecondaryButton.h"

#include "ui/my/Theme.h"

const QString SecondaryButton::QSS = Theme::instance().replace(R"(
SecondaryButton {
  color: SYM_COLOR_Z_800;
  background-color: SYM_COLOR_Z_050;
  min-height: 28px;
  min-width: 100px;
  border-radius: 4px;
  border: 1px solid SYM_COLOR_Z_500;
}
SecondaryButton::hover {
  background-color: SYM_COLOR_Z_100;
}
)");

SecondaryButton::SecondaryButton(JxWidget *parent) : JxPushButton(parent) { initUI(); }

void SecondaryButton::initUI() { this->setStyleSheet(QSS); }
