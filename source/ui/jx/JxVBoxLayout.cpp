#include "ui/jx/JxVBoxLayout.h"
#include <QDebug>
#include "ui/jx/JxWidget.h"

JxVBoxLayout::JxVBoxLayout(JxWidget *parent)
{
    this->initUI();
}

void JxVBoxLayout::initUI()
{
    this->setContentsMargins(0, 0, 0, 0);
}
