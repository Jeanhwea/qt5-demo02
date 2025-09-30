#include "app/Application.h"

#include "app/MainWindow.h"
#include "base/consts.h"
#include "base/logger.h"

Application::Application(int &argc, char **argv) : QApplication(argc, argv), m_win() {}

int Application::startup() {
  if (!init()) {
    return errcode::INIT_ERROR;
  }

  m_win.show();
  return exec();
}

bool Application::init() {
  Logger::instance()->setLogLevel(Debug);
  Logger::instance()->setConsoleOutput(true);
  return true;
}
