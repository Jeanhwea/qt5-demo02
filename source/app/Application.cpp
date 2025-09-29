#include "app/Application.h"

#include "base/consts.h"
#include "base/logger.h"
#include "ui/MainWindow.h"

Application::Application(int &argc, char **argv)
    : QApplication(argc, argv), m_win() {}

int Application::startup() {
  if (!init()) {
    return ErrorCode::InitError;
  }

  m_win.show();
  return exec();
}

bool Application::init() {
  Logger::getInstance()->setLogLevel(Debug);
  Logger::getInstance()->setConsoleOutput(true);
  return true;
}
