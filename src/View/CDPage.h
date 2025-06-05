#ifndef CDPAGE_H
#define CDPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QComboBox>
#include "../Model/CD.h"

class CDPage : public QWidget {
  Q_OBJECT

public:
  explicit CDPage(QWidget *parent = nullptr);
  void resetFields();

  signals:
    void CDSaved(const CD &cd);

private slots:
  void onConfirmClicked();

private:
  QLineEdit *nameEdit, *priceEdit, *copiesEdit, *imageEdit, *artistEdit, *
      publisherEdit, *durationEdit, *diameterEdit;
  QDateEdit *dateEdit;
  QComboBox *cdTypeCombo;
};


#endif // CDPAGE_H
