#include "BookPage.h"
#include <QFormLayout>
#include <QVBoxLayout>

BookPage::BookPage(QWidget *parent) : QWidget(parent) {
  auto formLayout = new QFormLayout;

  nameEdit = new QLineEdit(this);
  priceEdit = new QLineEdit(this);
  dateEdit = new QDateEdit(QDate::currentDate(), this);
  dateEdit->setCalendarPopup(true);
  copiesEdit = new QLineEdit(this);
  imageEdit = new QLineEdit(this);
  authorEdit = new QLineEdit(this);
  editorEdit = new QLineEdit(this);
  genreEdit = new QLineEdit(this);
  pagesEdit = new QLineEdit(this);
  bindingEdit = new QLineEdit(this);
  languageEdit = new QLineEdit(this);

  formLayout->addRow("Nome:", nameEdit);
  formLayout->addRow("Prezzo:", priceEdit);
  formLayout->addRow("Data:", dateEdit);
  formLayout->addRow("Copie Totali:", copiesEdit);
  formLayout->addRow("Immagine:", imageEdit);
  formLayout->addRow("Autore:", authorEdit);
  formLayout->addRow("Editore:", editorEdit);
  formLayout->addRow("Genere:", genreEdit);
  formLayout->addRow("Pagine:", pagesEdit);
  formLayout->addRow("Rilegatura:", bindingEdit);
  formLayout->addRow("Lingua Originale:", languageEdit);

  auto confirmButton = new QPushButton("Conferma", this);
  connect(confirmButton, &QPushButton::clicked, this,
          &BookPage::onConfirmClicked);

  auto mainLayout = new QVBoxLayout;
  mainLayout->addLayout(formLayout);
  mainLayout->addWidget(confirmButton);

  setLayout(mainLayout);
}

void BookPage::resetFields() {
  nameEdit->clear();
  priceEdit->clear();
  dateEdit->setDate(QDate::currentDate());
  copiesEdit->clear();
  imageEdit->clear();
  authorEdit->clear();
  editorEdit->clear();
  genreEdit->clear();
  pagesEdit->clear();
  bindingEdit->clear();
  languageEdit->clear();
}

void BookPage::onConfirmClicked() {
  Book book(
            nameEdit->text().toStdString(),
            priceEdit->text().toDouble(),
            dateEdit->dateTime(),
            copiesEdit->text().toInt(),
            imageEdit->text().toStdString(),
            authorEdit->text().toStdString(),
            editorEdit->text().toStdString(),
            genreEdit->text().toStdString(),
            pagesEdit->text().toInt(),
            bindingEdit->text().toStdString(),
            languageEdit->text().toStdString()
           );

  emit bookSaved(book);
}
