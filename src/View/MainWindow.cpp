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
  typeComboBox->addItems({"Book" , "CD"});

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

  // --- Pagina CD ---
  cdPage = new CDPage(this);
  connect(cdPage, &CDPage::CDSaved, this, &MainWindow::onCDSaved);
  stackedWidget->addWidget(cdPage);

  viewPage = new QWidget(this);
  auto *viewLayout = new QVBoxLayout(viewPage);

  tableWidget = new QTableWidget(this);


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
  if (typeComboBox->currentText() == "CD") {
    cdPage->resetFields(); // pulisce i campi
    stackedWidget->setCurrentWidget(cdPage);
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

  //books.push_back(book);
  products.push_back(std::make_unique<Book>(book));
  qDebug() << "Book salvato: " << QString::fromStdString(book.getName());
  stackedWidget->setCurrentWidget(homePage);
  QMessageBox::information(this, "Successo", "Libro aggiunto con successo!");
}

void MainWindow::onCDSaved(const CD &cd) {
  //cds.push_back(cd);
  products.push_back(std::make_unique<CD>(cd));
  qDebug() << "CD salvato: " << QString::fromStdString(cd.getName());
  stackedWidget->setCurrentWidget(homePage);
  QMessageBox::information(this, "Successo", "CD aggiunto con successo!");
}

void MainWindow::onViewClicked() {
  QString selectedType = typeComboBox->currentText();
  tableWidget->clearContents();

  if (selectedType == "Book") {
    tableWidget->setColumnCount(5);
    tableWidget->setHorizontalHeaderLabels({
      "Nome", "Autore", "Prezzo", "Copie", "Lingua"
    });

    int row = 0;
    for (const auto& p : products) {
      if (auto b = dynamic_cast<Book*>(p.get())) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(b->getName())));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(b->getAuthor())));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(b->getPrice())));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(b->getTotalCopies())));
        tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(b->getLanguage())));
        ++row;
      }
    }
    tableWidget->setRowCount(row);
  }

  else if (selectedType == "CD") {
    tableWidget->setColumnCount(5);
    tableWidget->setHorizontalHeaderLabels({
      "Nome", "Artista", "Prezzo", "Copie", "Tipo"
    });

    int row = 0;
    for (const auto& p : products) {
      if (auto c = dynamic_cast<CD*>(p.get())) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(c->getName())));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(c->getArtist())));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(c->getPrice())));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(c->getTotalCopies())));
        tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(c->getBookTypeAsString())));
        ++row;
      }
    }
    tableWidget->setRowCount(row);
  }

  tableWidget->horizontalHeader()->setStretchLastSection(true);
  stackedWidget->setCurrentWidget(viewPage);
}
