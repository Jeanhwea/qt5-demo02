#include "app/Application.h"

#include "base/logger.h"
#include "ui/MainWindow.h"

Application::Application(int &argc, char **argv)
    : QApplication(argc, argv), m_win() {}

int Application::run() {
  earlyInit();
  m_win.show();
  return exec();
}

void Application::earlyInit() {
  Logger::getInstance()->setLogLevel(Debug);
  Logger::getInstance()->setConsoleOutput(true);
}
