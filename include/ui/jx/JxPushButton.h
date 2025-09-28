#ifndef JXPUSHBUTTON_H
#define JXPUSHBUTTON_H

#include <QPushButton>

class JxPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit JxPushButton(QWidget *parent = nullptr);

private:
    static const QString QSS;
};

#endif // JXPUSHBUTTON_H
