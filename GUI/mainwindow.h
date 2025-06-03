#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QStackedWidget>
#include <vector>
#include "../Classi/Book.h"
#include "BookPage.h"
#include <QTableWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onAddClicked();
    void onBookSaved(const Book &book);
    void onViewClicked();

private:
    QStackedWidget *stackedWidget;
    QWidget *homePage;
    BookPage *bookPage;

    QComboBox *typeComboBox;
    QPushButton *addButton;

    std::vector<Book> books; // archivio locale

    QPushButton *viewButton;
    QWidget *viewPage;
    QTableWidget *tableWidget;
};

#endif // MAINWINDOW_H
