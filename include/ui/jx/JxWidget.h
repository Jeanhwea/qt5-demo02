#ifndef _JXWIDGET_H_
#define _JXWIDGET_H_

#include <QWidget>

class JxWidget : public QWidget {
  Q_OBJECT
public:
  explicit JxWidget(QWidget *parent = nullptr);

private:
  static const QString QSS;
};

#endif /* End of _JXWIDGET_H_ */
