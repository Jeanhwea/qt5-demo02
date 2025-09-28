#include "ui/jx/JxPushButton.h"
#include <QDebug>

const QString JxPushButton::QSS = R"(
JxPushButton {
  background-color: gray;
}
)";

JxPushButton::JxPushButton(QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet(QSS);
}
