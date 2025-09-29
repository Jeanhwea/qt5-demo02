#include "ui/jx/JxHBoxLayout.h"

#include "ui/jx/JxWidget.h"

JxHBoxLayout::JxHBoxLayout(JxWidget *parent) { initUI(); }

void JxHBoxLayout::initUI() { this->setContentsMargins(0, 0, 0, 0); }
