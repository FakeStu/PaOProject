#include <QApplication>
#include <QPushButton>
#include "View/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainWindow mainWindow;
  mainWindow.setWindowTitle("Biblioteca Virtuale");
  mainWindow.resize(400, 200);
  mainWindow.show();

  return app.exec();
}
