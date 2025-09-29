#include "ui/jx/JxVBoxLayout.h"

#include "ui/jx/JxWidget.h"

JxVBoxLayout::JxVBoxLayout(JxWidget *parent) { initUI(); }

void JxVBoxLayout::initUI() { this->setContentsMargins(0, 0, 0, 0); }
