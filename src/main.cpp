#include <QApplication>
#include "View/Window.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  Window mainWindow;
  mainWindow.setWindowTitle("Biblioteca Virtuale");
  mainWindow.resize(1600, 900);
  mainWindow.show();

  return app.exec();
}
