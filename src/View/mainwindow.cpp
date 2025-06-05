#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent) {
  stackedWidget = new QStackedWidget(this);
  setCentralWidget(stackedWidget);

  // --- Pagina principale ---
  homePage = new QWidget(this);
  auto mainLayout = new QVBoxLayout(homePage);
  auto *title = new QLabel("Seleziona tipo di prodotto da aggiungere:",
                           this);
  typeComboBox = new QComboBox(this);
  typeComboBox->addItems({"Book" /*, "CD", ...*/});

  addButton = new QPushButton("Aggiungi", this);
  connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddClicked);

  viewButton = new QPushButton("Visualizza", this);
  connect(viewButton, &QPushButton::clicked, this,
          &MainWindow::onViewClicked);
  mainLayout->addWidget(viewButton);

  mainLayout->addWidget(title);
  mainLayout->addWidget(typeComboBox);
  mainLayout->addWidget(addButton);
  homePage->setLayout(mainLayout);
  stackedWidget->addWidget(homePage);

  // --- Pagina Book ---
  bookPage = new BookPage(this);
  connect(bookPage, &BookPage::bookSaved, this, &MainWindow::onBookSaved);
  stackedWidget->addWidget(bookPage);

  viewPage = new QWidget(this);
  auto *viewLayout = new QVBoxLayout(viewPage);

  tableWidget = new QTableWidget(this);
  tableWidget->setColumnCount(5); // puoi aumentare se vuoi più dati
  tableWidget->setHorizontalHeaderLabels({
                                           "Nome", "Autore", "Prezzo", "Copie",
                                           "Lingua"
                                         });
  tableWidget->horizontalHeader()->setStretchLastSection(true);

  auto backButton = new QPushButton("Indietro", this);
  connect(backButton, &QPushButton::clicked, [this]() {
    stackedWidget->setCurrentWidget(homePage);
  });

  viewLayout->addWidget(tableWidget);
  viewLayout->addWidget(backButton);
  viewPage->setLayout(viewLayout);

  stackedWidget->addWidget(viewPage);

  stackedWidget->setCurrentWidget(homePage);
}

void MainWindow::onAddClicked() {
  if (typeComboBox->currentText() == "Book") {
    bookPage->resetFields(); // pulisce i campi
    stackedWidget->setCurrentWidget(bookPage);
  }
}

void MainWindow::onBookSaved(const Book &book) {
  QString name = QString::fromStdString(book.getName());
  QString author = QString::fromStdString(book.getAuthor());

  // Controllo campi obbligatori
  if (name.isEmpty()) {
    QMessageBox::warning(this, "Campo mancante", "Manca il campo Nome");
    return;
  }
  if (author.isEmpty()) {
    QMessageBox::warning(this, "Campo mancante", "Manca il campo Autore");
    return;
  }

  books.push_back(book);
  qDebug() << "Book salvato: " << QString::fromStdString(book.getName());
  stackedWidget->setCurrentWidget(homePage);
  QMessageBox::information(this, "Successo", "Libro aggiunto con successo!");
}

void MainWindow::onViewClicked() {
  if (typeComboBox->currentText() == "Book") {
    tableWidget->setRowCount(books.size());
    for (int i = 0; i < books.size(); ++i) {
      const Book &b = books[i];
      tableWidget->setItem(
                           i, 0, new QTableWidgetItem(
                            QString::fromStdString(b.getName())));
      tableWidget->setItem(
                           i, 1, new QTableWidgetItem(
                            QString::fromStdString(b.getAuthor())));
      tableWidget->setItem(
                           i, 2, new
                           QTableWidgetItem(QString::number(b.getPrice())));
      tableWidget->setItem(
                           i, 3, new QTableWidgetItem(
                            QString::number(b.getTotalCopies())));
      tableWidget->setItem(
                           i, 4, new QTableWidgetItem(
                            QString::fromStdString(b.getLanguage())));
    }
    stackedWidget->setCurrentWidget(viewPage);
  }
}
