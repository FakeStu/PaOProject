#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QStackedWidget>
#include <vector>
#include "../Model/Book.h"
#include "../Model/CD.h"
#include "BookPage.h"
#include "CDPage.h"
#include <QTableWidget>


class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);

private slots:
  void onAddClicked();
  void onBookSaved(const Book &book);
  void onCDSaved(const CD &cd);
  void onViewClicked();

private:
  QStackedWidget *stackedWidget;
  QWidget *homePage;
  BookPage *bookPage;
  CDPage *cdPage;

  QComboBox *typeComboBox;
  QPushButton *addButton;

  //FORSE DA FARE UN SINGOLO VECTOR DI PRODOTTI E NELLO VISUALIZZA X PUOI SCEGLIERE IL TIPO DA VEDERE
  /*std::vector<Book> books; // archivio locale libri
  std::vector<CD> cds;*/
  std::vector<std::unique_ptr<Product>> products;

  QPushButton *viewButton;
  QWidget *viewPage;
  QTableWidget *tableWidget;
};

#endif // MAINWINDOW_H

