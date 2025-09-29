#include "ui/jx/JxLabel.h"

#include <QDebug>

const QString JxLabel::QSS = R"(
JxLabel {
  background-color: none;
}
)";

JxLabel::JxLabel(JxWidget *parent) : QLabel(parent) { initUI(); }

void JxLabel::initUI() { this->setStyleSheet(QSS); }
