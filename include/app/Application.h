#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "ui/MainWindow.h"

#include <QApplication>

class Application : public QApplication {
public:
  Application(int &argc, char **argv);

public:
  int startup();

private:
  bool init();

private:
  MainWindow m_win;
};

#endif /* End of _APPLICATION_H_ */
