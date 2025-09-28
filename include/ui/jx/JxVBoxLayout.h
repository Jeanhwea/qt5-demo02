#ifndef _JXVBOXLAYOUT_H_
#define _JXVBOXLAYOUT_H_

#include <QVBoxLayout>

class JxVBoxLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit JxVBoxLayout(QWidget *parent = nullptr);

private:
    void initUI();
};

#endif /* End of _JXVBOXLAYOUT_H_ */
