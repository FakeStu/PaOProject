#include "RegisterProduct.h"

#include <QFormLayout>
#include <QPushButton>

RegisterProduct::RegisterProduct(QWidget *parent) : QWidget(parent) {
  const auto formLayout = new QFormLayout;

  _name = new QLineEdit(this);
  _price = new QLineEdit(this);
  _date = new QDateEdit(QDate::currentDate(), this);
  _date->setCalendarPopup(true);
  _copies = new QLineEdit(this);
  _image = new QLineEdit(this);

  formLayout->addRow("Name:", _name);
  formLayout->addRow("Price:", _price);
  formLayout->addRow("Date:", _date);
  formLayout->addRow("Total Copies:", _copies);
  formLayout->addRow("Picture:", _image);

  auto confirmButton = new QPushButton("Confirm", this);
  connect(confirmButton,
          &QPushButton::clicked,
          this,
          &RegisterProduct::onConfirmClicked);

  const auto mainLayout = new QVBoxLayout;
  mainLayout->addLayout(formLayout);
  mainLayout->addWidget(confirmButton);

  setLayout(mainLayout);
}

void RegisterProduct::resetFields() const {
  _name->clear();
  _price->clear();
  _date->setDate(QDate::currentDate());
  _copies->clear();
  _image->clear();
}

void RegisterProduct::onConfirmClicked() {
  auto* product = new Product (
                  _name->text().toStdString(),
                  _price->text().toDouble(),
                  _date->dateTime(),
                  _copies->text().toInt(),
                  _image->text().toStdString()
                 );
  emit productSaved(product);
}
