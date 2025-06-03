#ifndef BOOKPAGE_H
#define BOOKPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include "../Classi/Book.h"

class BookPage : public QWidget {
    Q_OBJECT

public:
    explicit BookPage(QWidget *parent = nullptr);
    void resetFields();

    signals:
        void bookSaved(const Book &book);

private slots:
    void onConfirmClicked();

private:
    QLineEdit *nameEdit, *priceEdit, *copiesEdit, *imageEdit, *authorEdit, *editorEdit, *genreEdit, *pagesEdit, *bindingEdit, *languageEdit;
    QDateEdit *dateEdit;
};

#endif // BOOKPAGE_H
