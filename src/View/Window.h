#ifndef PRODUCTFORMPAGE_H
#define PRODUCTFORMPAGE_H

#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QStackedWidget>
#include <QTableWidget>
#include <QWidget>
#include "..\Model\Product.h"


class Window : public QWidget {
  Q_OBJECT

public:
  explicit Window(QWidget *parent = nullptr);

signals:
  void bookAdded(QString name, QString author /* ... altri parametri */);
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

private:
  // Comuni
  QComboBox *typeCombo;
  QLineEdit *nameEdit;
  QLineEdit *priceEdit;
  QLineEdit *copiesEdit;
  QDateEdit *dateEdit;
  QLineEdit *imageEdit;

  // Specifici per Book
  QLineEdit *authorEdit;
  QLineEdit *editorEdit;
  QLineEdit *pagesEdit;
  QLineEdit *genreEdit;
  QLineEdit *bindingEdit;
  QLineEdit *languageEdit;

  // Specifici per CD
  QLineEdit *artistEdit;
  QLineEdit *publisherEdit;
  QLineEdit *durationEdit;
  QComboBox *bookTypeCombo;
  QLineEdit *diameterEdit;
  QLineEdit *versionEdit;

  // Specifici per Magazine
  QLineEdit *magAuthorEdit;
  QLineEdit *magEditorEdit;
  QLineEdit *magGenreEdit;
  QLineEdit *magPagesEdit;
  QComboBox *magPeriodicityCombo;
  QLineEdit *magTopicEdit;

  //Specifici per Comic
  QLineEdit *comicAuthorEdit;
  QLineEdit *comicEditorEdit;
  QLineEdit *comicGenreEdit;
  QLineEdit *comicPagesEdit;
  QComboBox *comicPeriodicityCombo;
  QLineEdit *comicVolumeEdit;
  QLineEdit *comicEditionEdit;

  // --- Vinyl specifici ---
  QLineEdit *vinylArtistEdit;
  QLineEdit *vinylPublisherEdit;
  QLineEdit *vinylDurationEdit;
  QComboBox *vinylFormatCombo;
  QComboBox *vinylSpeedCombo;
  QLineEdit *vinylColorEdit;

  // --- Film specifici ---
  QLineEdit *filmDirectorEdit;
  QLineEdit *filmPhotoDirectorEdit;
  QLineEdit *filmProtagonistEdit;
  QLineEdit *filmDurationEdit;
  QLineEdit *filmGenreEdit;

  QStackedWidget *specificStack; // per Book / CD
  QWidget *bookWidget;
  QWidget *cdWidget;
  QWidget *magazineWidget;
  QWidget *comicWidget;
  QWidget *vinylWidget;
  QWidget *filmWidget;

  QPushButton *searchButton;
  QPushButton *confirmButton;
  QPushButton *viewButton;
  QPushButton *deleteButton;
  QPushButton *exportButton;
  QPushButton *importButton;

  QTableWidget *tableWidget;

  QLineEdit *searchLineEdit;


  std::vector<std::shared_ptr<Product> > productList;

  void resetForm();
};

#endif // PRODUCTFORMPAGE_H
