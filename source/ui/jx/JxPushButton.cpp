#include "ui/jx/JxPushButton.h"
#include <QDebug>
#include "ui/jx/JxWidget.h"

const QString JxPushButton::QSS = R"(
JxPushButton {
  background-color: none;
}
)";

JxPushButton::JxPushButton(JxWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet(QSS);
}
