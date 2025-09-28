#ifndef JXPUSHBUTTON_H
#define JXPUSHBUTTON_H

#include <QPushButton>
#include "ui/jx/JxWidget.h"

class JxPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit JxPushButton(JxWidget *parent = nullptr);

private:
    void initUI();

    static const QString QSS;
};

#endif // JXPUSHBUTTON_H
