#include "ui/jx/JxPushButton.h"
#include <QDebug>

JxPushButton::JxPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "JxPushButton constructor";
}
