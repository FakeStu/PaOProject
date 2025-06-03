#include <QApplication>
#include <QPushButton>
#include "GUI/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Biblioteca Virtuale");
    mainWindow.resize(400, 200);
    mainWindow.show();

    return app.exec();
}
/*int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}*/