#ifndef PRODUCTFORMPAGE_H
#define PRODUCTFORMPAGE_H

#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QStackedWidget>
#include <QTableWidget>
#include <QWidget>
#include "../Model/Product.h"

class Window : public QWidget {
  Q_OBJECT

public:
  explicit Window(QWidget *parent = nullptr);

signals:
  void bookAdded(QString name, QString author /* ... altri parametri obbligatori*/);
  void cdAdded(QString name, QString artist /* ... */);
  void magazineAdded(QString name, QString author /* ... */);
  void comicAdded(QString name, QString author /* ... */);

private slots:
  void onTypeChanged(const QString &type);
  void onConfirmClicked();
  void onViewClicked();
  void onSearchClicked();
  void onDeleteClicked();
  void onExportClicked();
  void onImportClicked();
  void onEditClicked();
  void onUndoClicked();
  void onConfirmEditClicked();

private:
  // Select Type Product
  QComboBox *_typeInput;

  // Common Inputs
  QLineEdit *_nameInput;
  QLineEdit *_priceInput;
  QLineEdit *_copiesInput;
  QDateEdit *_dateInput;
  QLineEdit *_imageInput;

  // PaperProduct's Inputs
  QLineEdit *_authorInput;
  QLineEdit *_editorInput;
  QLineEdit *_paperProductGenreInput;
  QLineEdit *_pagesInput;

  // Book's Inputs
  QLineEdit *_bindingInput;
  QLineEdit *_languageInput;

  // Periodical's Inputs
  QComboBox *_periodicityInput;

  // Magazine's Inputs
  QLineEdit *_topicInput;

  // Comic's Inputs
  QLineEdit *_volumeInput;
  QLineEdit *_editionInput;

  // Disk's Inputs
  QLineEdit *_artistInput;
  QLineEdit *_publisherInput;
  QLineEdit *_diskDurationInput;

  // CD's Inputs
  QComboBox *_bookTypeInput;
  QLineEdit *_diameterInput;

  // Vinyl's Inputs
  QLineEdit *_colorInput;
  QComboBox *_formatInput;
  QComboBox *_speedInput;

  // Movie's Inputs
  QLineEdit *_directorInput;
  QLineEdit *_photoDirectorInput;
  QLineEdit *_protagonistInput;
  QLineEdit *_movieDurationInput;
  QLineEdit *_movieGenreInput;

  QStackedWidget *_specificProductWidget;

  // Widgets
  QWidget *_paperProductWidget;
  QWidget *_periodicalProductWidget;
  QWidget *_diskProductWidget;

  QWidget *_bookWidget;
  QWidget *_magazineWidget;
  QWidget *_comicWidget;
  QWidget *_cdWidget;
  QWidget *_vinylWidget;
  QWidget *_movieWidget;

  QPushButton *_confirmEditButton;
  QPushButton *_undoButton;
  QPushButton *_searchButton;
  QPushButton *_confirmButton;
  QPushButton *_viewButton;
  QPushButton *_deleteButton;
  QPushButton *_editButton;
  QPushButton *_exportButton;
  QPushButton *_importButton;

  QTableWidget *_tableWidget;

  QLineEdit *_searchInput;

  std::vector<std::shared_ptr<Product> > _productList;

  int indexInProductList = -1;

  void resetForm();
};

#endif // PRODUCTFORMPAGE_H
