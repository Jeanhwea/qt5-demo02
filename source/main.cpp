#include "components.h"
#include "logger.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  Logger::getInstance()->setLogLevel(Debug);
  Logger::getInstance()->setConsoleOutput(true);

  QApplication app(argc, argv);
  MainWindow win;
  win.show();
  return app.exec();
}
