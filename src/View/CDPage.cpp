//
// Created by Mattia on 05/06/2025.
//
#include "CDPage.h"
#include <QFormLayout>
#include <QVBoxLayout>

CDPage::CDPage(QWidget *parent) : QWidget(parent) {
  auto formLayout = new QFormLayout;

  nameEdit = new QLineEdit(this);
  priceEdit = new QLineEdit(this);
  dateEdit = new QDateEdit(QDate::currentDate(), this);
  dateEdit->setCalendarPopup(true);
  copiesEdit = new QLineEdit(this);
  imageEdit = new QLineEdit(this);
  artistEdit = new QLineEdit(this);
  publisherEdit = new QLineEdit(this);
  durationEdit = new QLineEdit(this);
  diameterEdit = new QLineEdit(this);
  cdTypeCombo = new QComboBox(this);
  cdTypeCombo->addItems({"Red", "Yellow", "Orange", "Green", "White", "Blue"});

  formLayout->addRow("Nome:", nameEdit);
  formLayout->addRow("Prezzo:", priceEdit);
  formLayout->addRow("Data:", dateEdit);
  formLayout->addRow("Copie Totali:", copiesEdit);
  formLayout->addRow("Immagine:", imageEdit);
  formLayout->addRow("Artista:", artistEdit);
  formLayout->addRow("Publisher:", publisherEdit);
  formLayout->addRow("Durata:", durationEdit);
  formLayout->addRow("Diametro:", diameterEdit);
  formLayout->addRow("Tipo:", cdTypeCombo);


  auto confirmButton = new QPushButton("Conferma", this);
  connect(confirmButton, &QPushButton::clicked, this,
          &CDPage::onConfirmClicked);

  auto mainLayout = new QVBoxLayout;
  mainLayout->addLayout(formLayout);
  mainLayout->addWidget(confirmButton);

  setLayout(mainLayout);
}

void CDPage::resetFields() {
  nameEdit->clear();
  priceEdit->clear();
  dateEdit->setDate(QDate::currentDate());
  copiesEdit->clear();
  imageEdit->clear();
  publisherEdit->clear();
  artistEdit->clear();
  durationEdit->clear();
  diameterEdit->clear();
}

void CDPage::onConfirmClicked() {
  int bookTypeIndex = cdTypeCombo->currentIndex();
  CD::BookType type = static_cast<CD::BookType>(bookTypeIndex);

  CD cd(
            nameEdit->text().toStdString(),
            priceEdit->text().toDouble(),
            dateEdit->dateTime(),
            copiesEdit->text().toInt(),
            imageEdit->text().toStdString(),
            publisherEdit->text().toStdString(),
            artistEdit->text().toStdString(),
            durationEdit->text().toInt(),
            diameterEdit->text().toInt(),
            type
           );

  emit CDSaved(cd);
}
