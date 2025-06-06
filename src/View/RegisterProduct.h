#ifndef REGISTERPRODUCT_H
#define REGISTERPRODUCT_H
#include <QDateEdit>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

#include "..\Model\Product.h"

class RegisterProduct : public QWidget {
  Q_OBJECT

private:
  QLineEdit *_name;
  QLineEdit *_price;
  QLineEdit *_copies;
  QLineEdit *_image;
  QDateEdit *_date;

  // Dynamic fields
  QMap<QString, QLineEdit*> specificFields;
  QString currentType;
  QFormLayout *formLayout;
  QPushButton *confirmButton;

public:
  explicit RegisterProduct(QWidget *parent = nullptr);
  void setProductType(const QString &type);
  void resetFields() const;

private slots:
  void onConfirmClicked();

signals:
  void productSaved(Product* product);
};
#endif //REGISTERPRODUCT_H
