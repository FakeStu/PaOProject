#include "Window.h"

#include <iostream>
#include <QFileDialog>
#include <QFormLayout>
#include <QHeaderView>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QMenu>
#include <QShortcut>
#include "../FileManagement/Export/JSON/JsonExportVisitor.h"
#include "../FileManagement/Export/XML/XmlExportVisitor.h"
#include "../FileManagement/Import/Import.h"
#include "../FileManagement/Import/JSON/JsonImport.h"
#include "../FileManagement/Import/XML/XmlImport.h"
#include "../Model/Book.h"
#include "../Model/CD.h"
#include "../Model/Comic.h"
#include "../Model/Magazine.h"
#include "../Model/Movie.h"
#include "../Model/Vinyl.h"
#include "../Visitor/ExportVisitor.h"


Window::Window(QWidget *parent) : QWidget(parent) {
  QFormLayout *mainLayout = new QFormLayout();
  auto *coolmainLayout = new QHBoxLayout(this);
  auto *sidebarLayout = new QFormLayout();

  _typeInput = new QComboBox(this);
  _typeInput->addItems({"Book", "Magazine", "Comic", "CD", "Vinyl", "Movie"});
  connect(_typeInput,
          &QComboBox::currentTextChanged,
          this,
          &Window::onTypeChanged);

  QIntValidator *validator = new QIntValidator(0, 10000, this);

  // Common Inputs
  {
    _nameInput = new QLineEdit(this);
    _priceInput = new QLineEdit(this);
    _priceInput->setValidator(validator);
    _copiesInput = new QLineEdit(this);
    _copiesInput->setValidator(validator);
    _dateInput = new QDateEdit(QDate::currentDate(), this);
    _dateInput->setCalendarPopup(true);
    _imageInput = new QLineEdit(this);

    sidebarLayout->addRow("Tipo:", _typeInput);
    sidebarLayout->addRow("Nome:", _nameInput);
    sidebarLayout->addRow("Prezzo:", _priceInput);
    sidebarLayout->addRow("Copie:", _copiesInput);
    sidebarLayout->addRow("Data:", _dateInput);
    sidebarLayout->addRow("Immagine:", _imageInput);
  }

  _specificProductWidget = new QStackedWidget(this);

  // PaperProduct Widget
  {
    _paperProductWidget = new QWidget(this);
    auto paperProductLayout = new QFormLayout(_paperProductWidget);

    _authorInput = new QLineEdit(this);
    _editorInput = new QLineEdit(this);
    _paperProductGenreInput = new QLineEdit(this);
    _pagesInput = new QLineEdit(this);
    _pagesInput->setValidator(validator);

    paperProductLayout->addRow("Author:", _authorInput);
    paperProductLayout->addRow("Publisher:", _editorInput);
    paperProductLayout->addRow("Number of pages:", _pagesInput);
    paperProductLayout->addRow("Genre:", _paperProductGenreInput);

    sidebarLayout->addRow("", _paperProductWidget);

    _paperProductWidget->hide();
  }

  // Book Widget
  {
    _bookWidget = new QWidget(this);
    auto *bookLayout = new QFormLayout(_bookWidget);

    _bindingInput = new QLineEdit(this);
    _languageInput = new QLineEdit(this);

    bookLayout->addRow("Binding:", _bindingInput);
    bookLayout->addRow("Original language:", _languageInput);

    _specificProductWidget->addWidget(_bookWidget);
  }

  // Periodical Widget
  {
    _periodicalProductWidget = new QWidget(this);
    auto *periodicalLayout = new QFormLayout(_periodicalProductWidget);

    _periodicityInput = new QComboBox(this);
    _periodicityInput->addItems({"Daily", "Weekly", "Monthly", "Annually"});

    periodicalLayout->addRow("Periodicity:", _periodicityInput);

    sidebarLayout->addRow("", _periodicalProductWidget);

    _periodicalProductWidget->hide();
  }

  // Magazine Widget
  {
    _magazineWidget = new QWidget(this);
    auto *magLayout = new QFormLayout(_magazineWidget);

    _topicInput = new QLineEdit(this);

    magLayout->addRow("Topic:", _topicInput);

    _specificProductWidget->addWidget(_magazineWidget);
  }

  // Comic Widget
  {
    _comicWidget = new QWidget(this);
    auto *comicLayout = new QFormLayout(_comicWidget);
    _volumeInput = new QLineEdit(this);
    _volumeInput->setValidator(validator);
    _editionInput = new QLineEdit(this);
    comicLayout->addRow("Volume:", _volumeInput);
    comicLayout->addRow("Edition:", _editionInput);
    _specificProductWidget->addWidget(_comicWidget);
  }

  // Disk Widget
  {
    _diskProductWidget = new QWidget(this);
    auto *diskLayout = new QFormLayout(_diskProductWidget);

    _artistInput = new QLineEdit(this);
    _publisherInput = new QLineEdit(this);
    _diskDurationInput = new QLineEdit(this);
    _diskDurationInput->setValidator(validator);

    diskLayout->addRow("Artist:", _artistInput);
    diskLayout->addRow("Publisher:", _publisherInput);
    diskLayout->addRow("Duration (min):", _diskDurationInput);

    sidebarLayout->addRow("", _diskProductWidget);

    _diskProductWidget->hide();
  }

  // CD Widget
  {
    _cdWidget = new QWidget(this);
    auto *cdLayout = new QFormLayout(_cdWidget);
    _bookTypeInput = new QComboBox(this);
    _bookTypeInput->addItems({
                               "Red",
                               "Yellow",
                               "Orange",
                               "Green",
                               "White",
                               "Blue"
                             });
    _diameterInput = new QLineEdit(this);
    _diameterInput->setValidator(validator);

    cdLayout->addRow("Tipo:", _bookTypeInput);
    cdLayout->addRow("Diametro:", _diameterInput);
    _specificProductWidget->addWidget(_cdWidget);
  }

  // Vinyl
  {
    _vinylWidget = new QWidget(this);
    auto *vinylLayout = new QFormLayout(_vinylWidget);


    _formatInput = new QComboBox(this);
    _formatInput->addItems({"12", "10", "7"});
    _speedInput = new QComboBox(this);
    _speedInput->addItems({"33", "45"});
    _colorInput = new QLineEdit(this);

    vinylLayout->addRow("Format:", _formatInput);
    vinylLayout->addRow("Speed:", _speedInput);
    vinylLayout->addRow("Color:", _colorInput);

    _specificProductWidget->addWidget(_vinylWidget);
  }

  // Movie
  {
    _movieWidget = new QWidget(this);
    auto *filmLayout = new QFormLayout(_movieWidget);

    _directorInput = new QLineEdit(this);
    _photoDirectorInput = new QLineEdit(this);
    _protagonistInput = new QLineEdit(this);
    _movieDurationInput = new QLineEdit(this);
    _movieDurationInput->setValidator(validator);
    _movieGenreInput = new QLineEdit(this);

    filmLayout->addRow("Director:", _directorInput);
    filmLayout->addRow("Photo Director:", _photoDirectorInput);
    filmLayout->addRow("Leading Actor:", _protagonistInput);
    filmLayout->addRow("Duration (min):", _movieDurationInput);
    filmLayout->addRow("Genre:", _movieGenreInput);

    _specificProductWidget->addWidget(_movieWidget);
  }

  auto *buttonsLayout = new QGridLayout();

  // Buttons
  {
    sidebarLayout->addRow(_specificProductWidget);

    _searchInput = new QLineEdit(this);
    _searchInput->setPlaceholderText("Cerca per nome");

    _searchButton = new QPushButton(this);
    _searchButton->setIcon(QIcon::fromTheme("edit-find"));
    _searchButton->setToolTip("Cerca");

    auto *searchLayout = new QHBoxLayout();
    searchLayout->addWidget(_searchInput);
    searchLayout->addWidget(_searchButton);

    // Search Button
    mainLayout->addRow("Cerca:", searchLayout);
    connect(_searchButton,
            &QPushButton::clicked,
            this,
            &Window::onSearchClicked);

    // Confirm Edit Button
    _confirmEditButton = new QPushButton("Conferma Modifica", this);
    connect(_confirmEditButton,
            &QPushButton::clicked,
            this,
            &Window::onConfirmEditClicked);
    sidebarLayout->addRow(_confirmEditButton);
    _confirmEditButton->hide();

    // Undo Button
    _undoButton = new QPushButton("Annulla", this);
    connect(_undoButton,
            &QPushButton::clicked,
            this,
            &Window::onUndoClicked);
    mainLayout->addRow(_undoButton);
    _undoButton->hide();
    // Confirm Button
    _confirmButton = new QPushButton("Aggiungi", this);
    connect(_confirmButton,
            &QPushButton::clicked,
            this,
            &Window::onConfirmClicked);
    sidebarLayout->addRow(_confirmButton);

    // View Button
    _viewButton = new QPushButton("Visualizza", this);
    sidebarLayout->addRow(_viewButton);
    connect(_viewButton,
            &QPushButton::clicked,
            this,
            &Window::onViewClicked);

    // Delete Button
    _deleteButton = new QPushButton("Elimina", this);
    sidebarLayout->addRow(_deleteButton);
    connect(_deleteButton,
            &QPushButton::clicked,
            this,
            &Window::onDeleteClicked);

    //Edit Button
    _editButton = new QPushButton("Modifica", this);
    sidebarLayout->addRow(_editButton);
    connect(_editButton,
            &QPushButton::clicked,
            this,
            &Window::onEditClicked);

    // Export Button
    _exportButton = new QPushButton("Export to File", this);
    sidebarLayout->addRow(_exportButton);
    connect(_exportButton,
            &QPushButton::clicked,
            this,
            &Window::onExportClicked);

    // Import Button
    _importButton = new QPushButton("Import from File", this);
    sidebarLayout->addRow(_importButton);
    connect(_importButton,
            &QPushButton::clicked,
            this,
            &Window::onImportClicked);
  }

  buttonsLayout->addWidget(_confirmEditButton, 0, 0);
  buttonsLayout->addWidget(_undoButton, 0, 1);

  buttonsLayout->addWidget(_confirmButton, 1, 0);
  buttonsLayout->addWidget(_viewButton, 1, 1);

  buttonsLayout->addWidget(_deleteButton, 2, 0);
  buttonsLayout->addWidget(_editButton, 2, 1);

  buttonsLayout->addWidget(_exportButton, 3, 0);
  buttonsLayout->addWidget(_importButton, 3, 1);

  sidebarLayout->addRow(buttonsLayout);

  _tableWidget = new QTableWidget(this);
  _tableWidget->setColumnCount(5);
  _tableWidget->horizontalHeader()->setStretchLastSection(true);
  _tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  mainLayout->addWidget(_tableWidget);

  onTypeChanged("Book");
  coolmainLayout->addLayout(sidebarLayout, 3);
  coolmainLayout->addLayout(mainLayout, 7);

  //SHORTCUT
  {
    QShortcut *deleteShortcut = new QShortcut(QKeySequence(Qt::Key_Delete), this);
    connect(deleteShortcut,
            &QShortcut::activated,
            this,
            [this]() {
              _deleteButton->click();
            });

    QShortcut *ctrlXShortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_X), this);
    connect(ctrlXShortcut,
            &QShortcut::activated,
            this,
            [this]() {
              _deleteButton->click();
            });

    connect(_searchInput,
            &QLineEdit::returnPressed,
            this,
            [this]() {
              _searchButton->click();
            });

    QShortcut *import_shortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_I), this);
    QShortcut *export_shortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_E), this);
    connect(import_shortcut,
            &QShortcut::activated,
            this,
            [this]() {
              _importButton->click();
            });
    connect(export_shortcut,
            &QShortcut::activated,
            this,
            [this]() {
              _exportButton->click();
            });
  }
}

void Window::resetForm() {
  // Common Inputs
  {
    _nameInput->clear();
    _priceInput->clear();
    _copiesInput->clear();
    _imageInput->clear();
    _dateInput->setDate(QDate::currentDate());
  }

  // PaperProduct Inputs
  {
    _authorInput->clear();
    _editorInput->clear();
    _paperProductGenreInput->clear();
    _pagesInput->clear();
  }

  // Book Inputs
  {
    _authorInput->clear();
    _editorInput->clear();
    _paperProductGenreInput->clear();
    _pagesInput->clear();
    _bindingInput->clear();
    _languageInput->clear();
  }

  // Periodical Inputs
  {
    _periodicityInput->clear();
  }

  // Magazine
  {
    _topicInput->clear();
  }

  // Comic
  {
    _volumeInput->clear();
    _editionInput->clear();
  }

  // Disk Inputs
  {
    _artistInput->clear();
    _publisherInput->clear();
    _diskDurationInput->clear();
  }

  // CD Inputs
  {
    _diameterInput->clear();
    _bookTypeInput->setCurrentIndex(0);
  }

  //Vinyl
  {
    _formatInput->setCurrentIndex(0);
    _speedInput->setCurrentIndex(0);
    _colorInput->clear();
  }

  //Film
  {
    _directorInput->clear();
    _photoDirectorInput->clear();
    _protagonistInput->clear();
    _movieDurationInput->clear();
    _movieGenreInput->clear();
  }
}

void Window::onTypeChanged(const QString &type) {
  _deleteButton->setDisabled(true);
  _editButton->setDisabled(true);
  if (type == "Magazine" || type == "Comic") {
    _paperProductWidget->show();
    _periodicalProductWidget->show();
    _diskProductWidget->hide();
  } else if (type == "Book") {
    _paperProductWidget->show();
    _periodicalProductWidget->hide();
    _diskProductWidget->hide();
  } else if (type == "CD" || type == "Vinyl") {
    _paperProductWidget->hide();
    _periodicalProductWidget->hide();
    _diskProductWidget->show();
  } else {
    _paperProductWidget->hide();
    _periodicalProductWidget->hide();
    _diskProductWidget->hide();
  }

  if (type == "Book") _specificProductWidget->setCurrentWidget(_bookWidget);
  else if (type == "CD") _specificProductWidget->setCurrentWidget(_cdWidget);
  else if (type == "Magazine") _specificProductWidget->setCurrentWidget(_magazineWidget);
  else if (type == "Comic") _specificProductWidget->setCurrentWidget(_comicWidget);
  else if (type == "Vinyl") _specificProductWidget->setCurrentWidget(_vinylWidget);
  else if (type == "Movie") _specificProductWidget->setCurrentWidget(_movieWidget);
}

void Window::onConfirmClicked() {
  QString type = _typeInput->currentText();

  // Campi comuni
  std::string name = _nameInput->text().toStdString();
  double price = _priceInput->text().toDouble();
  QDateTime date = _dateInput->dateTime();
  int copies = _copiesInput->text().toInt();
  std::string image = _imageInput->text().toStdString();

  if (name.empty()) {
    QMessageBox::warning(this, "Errore", "Manca il campo Nome");
    return;
  }

  if (type == "Book") {
    std::string author = _authorInput->text().toStdString();
    if (author.empty()) {
      QMessageBox::warning(this, "Errore", "Manca il campo Autore");
      return;
    }
    std::string editor = _editorInput->text().toStdString();
    std::string genre = _paperProductGenreInput->text().toStdString();
    int pages = _pagesInput->text().toInt();
    std::string binding = _bindingInput->text().toStdString();
    std::string language = _languageInput->text().toStdString();

    std::shared_ptr<Book> newBook = std::make_shared<Book>(
                                                           name,
                                                           price,
                                                           date,
                                                           copies,
                                                           image,
                                                           author,
                                                           editor,
                                                           genre,
                                                           pages,
                                                           binding,
                                                           language);

    _productList.push_back(newBook);
    QMessageBox::information(this, "Successo", "Libro aggiunto con successo");
  } else if (type == "CD") {
    std::string artist = _artistInput->text().toStdString();
    std::string publisher = _publisherInput->text().toStdString();
    int duration = _diskDurationInput->text().toInt();
    int diameter = _diameterInput->text().toInt();

    QString typeStr = _bookTypeInput->currentText();
    CD::BookType bookType;
    if (typeStr == "Red") bookType = CD::Red;
    else if (typeStr == "Yellow") bookType = CD::Yellow;
    else if (typeStr == "Orange") bookType = CD::Orange;
    else if (typeStr == "Green") bookType = CD::Green;
    else if (typeStr == "White") bookType = CD::White;
    else bookType = CD::Blue;

    std::shared_ptr<CD> newCD = std::make_shared<CD>(
                                                     name,
                                                     price,
                                                     date,
                                                     copies,
                                                     image,
                                                     artist,
                                                     publisher,
                                                     duration,
                                                     diameter,
                                                     bookType);

    _productList.push_back(newCD);
    QMessageBox::information(this, "Successo", "CD aggiunto con successo");
  } else if (type == "Magazine") {
    std::string author = _authorInput->text().toStdString();
    if (author.empty()) {
      QMessageBox::warning(this, "Errore", "Manca il campo Autore");
      return;
    }
    std::string editor = _editorInput->text().toStdString();
    std::string genre = _paperProductGenreInput->text().toStdString();
    int pages = _pagesInput->text().toInt();
    QString perStr = _periodicityInput->currentText();
    Periodical::periodicalType periodicity;
    if (perStr == "Daily") periodicity = Periodical::daily;
    else if (perStr == "Weekly") periodicity = Periodical::weekly;
    else if (perStr == "Monthly") periodicity = Periodical::monthly;
    else periodicity = Periodical::annually;
    std::string topic = _topicInput->text().toStdString();

    std::shared_ptr<Magazine> newMagazine = std::make_shared<Magazine>(
                                                                       name,
                                                                       price,
                                                                       date,
                                                                       copies,
                                                                       image,
                                                                       author,
                                                                       editor,
                                                                       genre,
                                                                       pages,
                                                                       periodicity,
                                                                       topic);

    _productList.push_back(newMagazine);
    QMessageBox::information(this,
                             "Successo",
                             "Magazine aggiunto con successo");
  } else if (type == "Comic") {
    std::string author = _authorInput->text().toStdString();
    if (author.empty()) {
      QMessageBox::warning(this, "Errore", "Manca il campo Autore");
      return;
    }
    std::string editor = _editorInput->text().toStdString();
    std::string genre = _paperProductGenreInput->text().toStdString();
    int pages = _pagesInput->text().toInt();
    QString perStr = _periodicityInput->currentText();
    Periodical::periodicalType periodicity;
    if (perStr == "Daily") periodicity = Periodical::daily;
    else if (perStr == "Weekly") periodicity = Periodical::weekly;
    else if (perStr == "Monthly") periodicity = Periodical::monthly;
    else periodicity = Periodical::annually;
    int volume = _volumeInput->text().toInt();
    std::string edition = _editionInput->text().toStdString();

    std::shared_ptr<Comic> newComic = std::make_shared<Comic>(
                                                              name,
                                                              price,
                                                              date,
                                                              copies,
                                                              image,
                                                              author,
                                                              editor,
                                                              genre,
                                                              pages,
                                                              periodicity,
                                                              volume,
                                                              edition);

    _productList.push_back(newComic);
    QMessageBox::information(this, "Successo", "Comic aggiunto con successo");
  } else if (type == "Vinyl") {
    std::string artist = _artistInput->text().toStdString();
    std::string publisher = _publisherInput->text().toStdString();
    int duration = _diskDurationInput->text().toInt();
    int formatInt = _formatInput->currentText().toInt();
    Vinyl::FormatType format;
    switch (formatInt) {
      case 12:
        format = Vinyl::FormatType::Twelve;
        break;
      case 10:
        format = Vinyl::FormatType::Ten;
        break;
      case 7:
        format = Vinyl::FormatType::Seven;
        break;
      default:
        format = Vinyl::FormatType::Twelve; // default
    }
    int speedInt = _speedInput->currentText().toInt();
    Vinyl::SpeedType speed = (speedInt == 33)
                               ? Vinyl::SpeedType::ThirtyThree
                               : Vinyl::SpeedType::FortyFive;
    std::string color = _colorInput->text().toStdString();

    std::shared_ptr<Vinyl> newVinyl = std::make_shared<Vinyl>(
                                                              name,
                                                              price,
                                                              date,
                                                              copies,
                                                              image,
                                                              artist,
                                                              publisher,
                                                              duration,
                                                              color,
                                                              format,
                                                              speed
                                                             );
    _productList.push_back(newVinyl);
    QMessageBox::information(this, "Successo", "Vinyl aggiunto con successo");
  } else if (type == "Movie") {
    std::string director = _directorInput->text().toStdString();
    std::string photoDirector = _photoDirectorInput->text().toStdString();
    std::string protagonist = _protagonistInput->text().toStdString();
    int duration = _movieDurationInput->text().toInt();
    std::string genre = _movieGenreInput->text().toStdString();

    std::shared_ptr<Movie> newFilm = std::make_shared<Movie>(
                                                             name,
                                                             price,
                                                             date,
                                                             copies,
                                                             image,
                                                             director,
                                                             photoDirector,
                                                             protagonist,
                                                             duration,
                                                             genre
                                                            );
    _productList.push_back(newFilm);
    QMessageBox::information(this, "Successo", "Film aggiunto con successo");
  }


  resetForm();
}

void Window::onViewClicked() {
  _deleteButton->setDisabled(false);
  _editButton->setDisabled(false);
  QString selected = _typeInput->currentText();

  _tableWidget->clear();
  _tableWidget->setRowCount(0);

  if (selected == "Book") {
    _tableWidget->setColumnCount(5);
    _tableWidget->setHorizontalHeaderLabels({
                                              "Nome",
                                              "Autore",
                                              "Prezzo",
                                              "Copie",
                                              "Lingua"
                                            });

    int row = 0;
    for (const auto &product: _productList) {
      auto book = std::dynamic_pointer_cast<Book>(product);
      if (book) {
        _tableWidget->insertRow(row);
        _tableWidget->setItem(row,
                              0,
                              new
                              QTableWidgetItem(QString::fromStdString(book->
                                                                      getName())));
        _tableWidget->setItem(row,
                              1,
                              new QTableWidgetItem(QString::fromStdString(book->
                                                                          getAuthor())));
        _tableWidget->setItem(row,
                              2,
                              new QTableWidgetItem(QString::number(book->
                                                                   getPrice())));
        _tableWidget->setItem(row,
                              3,
                              new QTableWidgetItem(QString::number(book->
                                                                   getTotalCopies())));
        _tableWidget->setItem(row,
                              4,
                              new QTableWidgetItem(QString::fromStdString(book->
                                                                          getLanguage())));
        ++row;
      }
    }
  } else if (selected == "CD") {
    _tableWidget->setColumnCount(5);
    _tableWidget->setHorizontalHeaderLabels({
                                              "Nome",
                                              "Artista",
                                              "Prezzo",
                                              "Copie",
                                              "Durata"
                                            });

    int row = 0;
    for (const auto &product: _productList) {
      auto cd = std::dynamic_pointer_cast<CD>(product);
      if (cd) {
        _tableWidget->insertRow(row);
        _tableWidget->setItem(row,
                              0,
                              new
                              QTableWidgetItem(QString::fromStdString(cd->
                                                                      getName())));
        _tableWidget->setItem(row,
                              1,
                              new
                              QTableWidgetItem(QString::fromStdString(cd->
                                                                      getArtist())));
        _tableWidget->setItem(row,
                              2,
                              new
                              QTableWidgetItem(QString::number(cd->getPrice())));
        _tableWidget->setItem(row,
                              3,
                              new
                              QTableWidgetItem(QString::number(cd->
                                                               getTotalCopies())));
        _tableWidget->setItem(row,
                              4,
                              new
                              QTableWidgetItem(QString::number(cd->getDuration())));
        ++row;
      }
    }
  } else if (selected == "Magazine") {
    _tableWidget->setColumnCount(6);
    _tableWidget->setHorizontalHeaderLabels({
                                              "Nome",
                                              "Autore",
                                              "Prezzo",
                                              "Copie",
                                              "Periodicità",
                                              "Topic"
                                            });

    int row = 0;
    for (const auto &product: _productList) {
      auto mag = std::dynamic_pointer_cast<Magazine>(product);
      if (mag) {
        _tableWidget->insertRow(row);
        _tableWidget->setItem(row,
                              0,
                              new
                              QTableWidgetItem(QString::fromStdString(mag->
                                                                      getName())));
        _tableWidget->setItem(row,
                              1,
                              new
                              QTableWidgetItem(QString::fromStdString(mag->
                                                                      getAuthor())));
        _tableWidget->setItem(row,
                              2,
                              new
                              QTableWidgetItem(QString::number(mag->getPrice())));
        _tableWidget->setItem(row,
                              3,
                              new QTableWidgetItem(QString::number(mag->
                                                                   getTotalCopies())));

        QString periodicityStr;
        QString p = QString::fromStdString(mag->getPeriodicityAsString());

        if (p == "daily") periodicityStr = "Daily";
        else if (p == "weekly") periodicityStr = "Weekly";
        else if (p == "monthly") periodicityStr = "Monthly";
        else if (p == "annually") periodicityStr = "Annually";
        else periodicityStr = "Unknown";


        _tableWidget->setItem(row, 4, new QTableWidgetItem(periodicityStr));
        _tableWidget->setItem(row,
                              5,
                              new
                              QTableWidgetItem(QString::fromStdString(mag->
                                                                      getTopic())));
        ++row;
      }
    }
  } else if (selected == "Comic") {
    _tableWidget->setColumnCount(7);
    _tableWidget->setHorizontalHeaderLabels({
                                              "Nome",
                                              "Autore",
                                              "Prezzo",
                                              "Copie",
                                              "Periodicità",
                                              "Volume",
                                              "Edizione"
                                            });

    int row = 0;
    for (const auto &product: _productList) {
      auto comic = std::dynamic_pointer_cast<Comic>(product);
      if (comic) {
        _tableWidget->insertRow(row);
        _tableWidget->setItem(row,
                              0,
                              new QTableWidgetItem(QString::fromStdString(comic->
                                                                          getName())));
        _tableWidget->setItem(row,
                              1,
                              new QTableWidgetItem(QString::fromStdString(comic->
                                                                          getAuthor())));
        _tableWidget->setItem(row,
                              2,
                              new QTableWidgetItem(QString::number(comic->
                                                                   getPrice())));
        _tableWidget->setItem(row,
                              3,
                              new QTableWidgetItem(QString::number(comic->
                                                                   getTotalCopies())));

        QString periodicityStr;
        QString p = QString::fromStdString(comic->getPeriodicityAsString());

        if (p == "daily") periodicityStr = "Daily";
        else if (p == "weekly") periodicityStr = "Weekly";
        else if (p == "monthly") periodicityStr = "Monthly";
        else if (p == "annually") periodicityStr = "Annually";
        else periodicityStr = "Unknown";

        _tableWidget->setItem(row, 4, new QTableWidgetItem(periodicityStr));
        _tableWidget->setItem(row,
                              5,
                              new QTableWidgetItem(QString::number(comic->
                                                                   getVolume())));
        _tableWidget->setItem(row,
                              6,
                              new QTableWidgetItem(QString::fromStdString(comic->
                                                                          getEdition())));
        ++row;
      }
    }
  } else if (selected == "Vinyl") {
    _tableWidget->setColumnCount(7);
    _tableWidget->setHorizontalHeaderLabels({
                                              "Nome",
                                              "Artista",
                                              "Editore",
                                              "Durata",
                                              "Formato",
                                              "Velocità",
                                              "Colore"
                                            });

    int row = 0;
    for (const auto &product: _productList) {
      auto vinyl = std::dynamic_pointer_cast<Vinyl>(product);
      if (vinyl) {
        _tableWidget->insertRow(row);
        _tableWidget->setItem(row,
                              0,
                              new QTableWidgetItem(QString::fromStdString(vinyl->
                                                                          getName())));
        _tableWidget->setItem(row,
                              1,
                              new QTableWidgetItem(QString::fromStdString(vinyl->
                                                                          getArtist())));
        _tableWidget->setItem(row,
                              2,
                              new QTableWidgetItem(QString::fromStdString(vinyl->
                                                                          getPublisher())));
        _tableWidget->setItem(row,
                              3,
                              new QTableWidgetItem(QString::number(vinyl->
                                                                   getDuration())));
        _tableWidget->setItem(row,
                              4,
                              new QTableWidgetItem(QString::fromStdString(vinyl->
                                                                          getFormatAsString())));
        _tableWidget->setItem(row,
                              5,
                              new QTableWidgetItem(QString::fromStdString(vinyl->
                                                                          getSpeedAsString())));
        _tableWidget->setItem(row,
                              6,
                              new QTableWidgetItem(QString::fromStdString(vinyl->
                                                                          getColor())));
        ++row;
      }
    }
  } else if (selected == "Movie") {
    _tableWidget->setColumnCount(6);
    _tableWidget->setHorizontalHeaderLabels({
                                              "Nome",
                                              "Regista",
                                              "Direttore Foto",
                                              "Protagonista",
                                              "Durata",
                                              "Genere"
                                            });

    int row = 0;
    for (const auto &product: _productList) {
      auto film = std::dynamic_pointer_cast<Movie>(product);
      if (film) {
        _tableWidget->insertRow(row);
        _tableWidget->setItem(row,
                              0,
                              new
                              QTableWidgetItem(QString::fromStdString(film->
                                                                      getName())));
        _tableWidget->setItem(row,
                              1,
                              new QTableWidgetItem(QString::fromStdString(film->
                                                                          getDirector())));
        _tableWidget->setItem(row,
                              2,
                              new QTableWidgetItem(QString::fromStdString(film->
                                                                          getPhotoDirector())));
        _tableWidget->setItem(row,
                              3,
                              new QTableWidgetItem(QString::fromStdString(film->
                                                                          getProtagonist())));
        _tableWidget->setItem(row,
                              4,
                              new QTableWidgetItem(QString::number(film->
                                                                   getDuration())));
        _tableWidget->setItem(row,
                              5,
                              new
                              QTableWidgetItem(QString::fromStdString(film->
                                                                      getGenre())));
        ++row;
      }
    }
  }
}

void Window::onSearchClicked() {
  _deleteButton->setDisabled(true);
  _editButton->setDisabled(true);
  QString searchText = _searchInput->text().trimmed();
  if (searchText.isEmpty()) return;

  _tableWidget->clear();
  _tableWidget->setRowCount(0);
  _tableWidget->setColumnCount(4);
  _tableWidget->setHorizontalHeaderLabels({"Tipo", "Nome", "Prezzo", "Copie"});

  int row = 0;
  for (const auto &product: _productList) {
    QString name = QString::fromStdString(product->getName());
    if (name.contains(searchText, Qt::CaseInsensitive)) {
      _tableWidget->insertRow(row);

      QString type;

      if (dynamic_cast<Book *>(product.get())) type = "Book";
      else if (dynamic_cast<CD *>(product.get())) type = "CD";
      else if (dynamic_cast<Magazine *>(product.get())) type = "Magazine";
      else if (dynamic_cast<Comic *>(product.get())) type = "Comic";
      else if (dynamic_cast<Vinyl *>(product.get())) type = "Vinyl";
      else if (dynamic_cast<Movie *>(product.get())) type = "Movie";
      else type = "Sconosciuto";

      _tableWidget->setItem(row, 0, new QTableWidgetItem(type));
      _tableWidget->setItem(row, 1, new QTableWidgetItem(name));
      _tableWidget->setItem(row,
                            2,
                            new QTableWidgetItem(QString::number(product->
                                                                 getPrice())));
      _tableWidget->setItem(row,
                            3,
                            new QTableWidgetItem(QString::number(product->
                                                                 getTotalCopies())));
      ++row;
    }
  }


  if (row == 0) {
    QMessageBox::information(this,
                             "Nessun risultato",
                             "Nessun prodotto trovato con questo nome.");
  }
}

void Window::onDeleteClicked() {
  int currentRow = _tableWidget->currentRow();

  if (currentRow < 0) {
    QMessageBox::warning(this, "Errore", "Nessun elemento selezionato");
    return;
  }

  // Mostra finestra di conferma
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this,
                                "Conferma eliminazione",
                                "Sei sicuro di voler eliminare l'elemento selezionato?",
                                QMessageBox::Yes | QMessageBox::No);

  if (reply != QMessageBox::Yes) {
    return; // annullato
  }
indexInProductList = -1;
  QString selectedType = _typeInput->currentText();
  int count = 0;
  indexInProductList = -1;
  for (size_t i = 0; i < _productList.size(); ++i) {
    if (selectedType == "Book" && std::dynamic_pointer_cast<
          Book>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    } else if (selectedType == "CD" && std::dynamic_pointer_cast<
                 CD>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    } else if (selectedType == "Magazine" && std::dynamic_pointer_cast<
                 Magazine>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    } else if (selectedType == "Comic" && std::dynamic_pointer_cast<
                 Comic>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    } else if (selectedType == "Vinyl" && std::dynamic_pointer_cast<
                 Vinyl>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    } else if (selectedType == "Movie" && std::dynamic_pointer_cast<
                 Movie>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    }
  }

  if (indexInProductList >= 0) {
    _productList.erase(_productList.begin() + indexInProductList);
    onViewClicked(); // aggiorna la tabella completamente
    QMessageBox::information(this,
                             "Successo",
                             "Elemento eliminato con successo");
  } else {
    QMessageBox::warning(this,
                         "Errore",
                         "Impossibile eliminare l'elemento selezionato");
  }
}

void Window::onExportClicked() {
  // Check if there are products to export
  if (_productList.empty()) {
    QMessageBox::warning(this, "Error", "There are no products to export");
    return;
  }

  // File's types that can be exported
  QStringList items;
  items << "JSON" << "XML";
  bool ok;
  // Input Dialog to choose the file type
  const QString fileType = QInputDialog::getItem(this,
                                                 "Export products",
                                                 "Choose the file type to export",
                                                 items,
                                                 0,
                                                 false,
                                                 &ok);

  // Input Dialog to choose the file name
  QString fileName = QFileDialog::getSaveFileName(this,
                                                  "Save" + fileType,
                                                  "",
                                                  "All Files (*)");

  // Check if the user provided a file name
  if (fileName.isEmpty()) {
    QMessageBox::warning(this, "Error", "No file name provided for export");
    return;
  }

  // Check if the file name ends with the correct extension
  const QString extension = "." + fileType.toLower();
  if (!fileName.endsWith(extension, Qt::CaseInsensitive))
    fileName += extension;

  std::unique_ptr<ExportVisitor> visitor;
  // Export logic based on the selected file type
  if (extension == ".json") {
    visitor = std::make_unique<JsonExportVisitor>();
  } else if (extension == ".xml") {
    visitor = std::make_unique<XmlExportVisitor>();
  } else {
    // Default
    QMessageBox::warning(this, "Error", "No type selected for export");
  }

  try {
    visitor->exportToFile(fileName, _productList);
    QMessageBox::information(this,
                             "Success",
                             "Products exported successfully " + fileName);
  } catch (const std::exception &e) {
    QMessageBox::critical(this,
                          "Error",
                          "Error during export: " + QString(e.what()));
  }
}

void Window::onImportClicked() {
  QString fileName = QFileDialog::getOpenFileName(this,
                                                  "Load File",
                                                  "",
                                                  "All Files (*)");


  if (fileName.isEmpty()) {
    return;
  }


  // Get the file extension
  const QString extension = QFileInfo(fileName).suffix().toLower();
  std::cout << "File extension: " << extension.toStdString();
  std::unique_ptr<Import> importer;

  if (extension == "json")
    importer = std::make_unique<JsonImport>();
  else if (extension == "xml")
    importer = std::make_unique<XmlImport>();
  else {
    QMessageBox::warning(this, "Error", "Unsupported file type for import");
    return;
  }

  try {
    auto importedProducts = importer->importFromFile(fileName);

    if (importedProducts.empty()) {
      QMessageBox::warning(this, "Error", "No products found in the file");
      return;
    }

    // Add imported products to the existing list
    _productList.insert(_productList.end(),
                        importedProducts.begin(),
                        importedProducts.end());

    QMessageBox::information(this,
                             "Success",
                             QString("Imported %1 products from: %2")
                             .arg(importedProducts.size())
                             .arg(fileName));

  } catch (const std::exception &e) {
    QMessageBox::critical(this,
                          "Error",
                          "Error when trying to import: " + QString(e.what()));
  }
}

void Window::onEditClicked() {
  int currentRow = _tableWidget->currentRow();

  if (currentRow < 0) {
    QMessageBox::warning(this, "Errore", "Nessun elemento selezionato");
    return;
  }

  // Mostra finestra di conferma
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this,
                                "Conferma eliminazione",
                                "Sei sicuro di voler modificare l'elemento selezionato?",
                                QMessageBox::Yes | QMessageBox::No);

  if (reply != QMessageBox::Yes) {
    return; // annullato
  }

  //You can only edit the product if it is selected in the table
  _confirmButton->setDisabled(true);
  _searchButton->setDisabled(true);
  _deleteButton->setDisabled(true);
  _editButton->setDisabled(true);
  _viewButton->setDisabled(true);
  _importButton->setDisabled(true);
  _exportButton->setDisabled(true);
  _typeInput->setDisabled(true);
  _confirmEditButton->show();
  _undoButton->show();

  QString selectedType = _typeInput->currentText();
  int count = 0;
  indexInProductList = -1;
  for (size_t i = 0; i < _productList.size(); ++i) {
    if (selectedType == "Book" && std::dynamic_pointer_cast<
          Book>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    } else if (selectedType == "CD" && std::dynamic_pointer_cast<
                 CD>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    } else if (selectedType == "Magazine" && std::dynamic_pointer_cast<
                 Magazine>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    } else if (selectedType == "Comic" && std::dynamic_pointer_cast<
                 Comic>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    } else if (selectedType == "Vinyl" && std::dynamic_pointer_cast<
                 Vinyl>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    } else if (selectedType == "Movie" && std::dynamic_pointer_cast<
                 Movie>(_productList[i])) {
      if (count == currentRow) {
        indexInProductList = static_cast<int>(i);
        break;
      }
      ++count;
    }
  }
  if (indexInProductList >= 0) {
    Product *product = _productList[indexInProductList].get();
    _nameInput->setText(QString::fromStdString(product->getName()));
    _priceInput->setText(QString::number(product->getPrice()));
    _copiesInput->setText(QString::number(product->getTotalCopies()));
    _dateInput->setDate(product->getDate().date());
    _imageInput->setText(QString::fromStdString(product->getImage()));
    if (auto paperProduct = dynamic_cast<PaperProduct *>(product)) {
      _authorInput->setText(QString::fromStdString(paperProduct->getAuthor()));
      _editorInput->setText(QString::fromStdString(paperProduct->getPublisher()));
      _paperProductGenreInput->setText(QString::fromStdString(paperProduct->getGenre()));
      _pagesInput->setText(QString::number(paperProduct->getPages()));
    }
    if (auto book = dynamic_cast<Book *>(product)) {
      _bindingInput->setText(QString::fromStdString(book->getBinding()));
      _languageInput->setText(QString::fromStdString(book->getLanguage()));
    } else if (auto magazine = dynamic_cast<Magazine *>(product)) {
      QString periodicityStr;
      QString p = QString::fromStdString(magazine->getPeriodicityAsString());
      if (p == "daily") periodicityStr = "Daily";
      else if (p == "weekly") periodicityStr = "Weekly";
      else if (p == "monthly") periodicityStr = "Monthly";
      else periodicityStr = "Annually";
      _periodicityInput->setCurrentText(periodicityStr);
      _topicInput->setText(QString::fromStdString(magazine->getTopic()));
    } else if (auto comic = dynamic_cast<Comic *>(product)) {
      QString periodicityStr;
      QString p = QString::fromStdString(comic->getPeriodicityAsString());
      if (p == "daily") periodicityStr = "Daily";
      else if (p == "weekly") periodicityStr = "Weekly";
      else if (p == "monthly") periodicityStr = "Monthly";
      else periodicityStr = "Annually";
      _periodicityInput->setCurrentText(periodicityStr);
      _volumeInput->setText(QString::number(comic->getVolume()));
      _editionInput->setText(QString::fromStdString(comic->getEdition()));
    }
    if (auto disk = dynamic_cast<Disk *>(product)) {
      _artistInput->setText(QString::fromStdString(disk->getArtist()));
      _publisherInput->setText(QString::fromStdString(disk->getPublisher()));
      _diskDurationInput->setText(QString::number(disk->getDuration()));
    }
    if (auto cd = dynamic_cast<CD *>(product)) {
      _diameterInput->setText(QString::number(cd->getDiameter()));
      QString booktypeStr;
      QString p = QString::fromStdString(cd->getBookTypeAsString());
      if (p == "daily") booktypeStr = "Daily";
      else if (p == "weekly") booktypeStr = "Weekly";
      else if (p == "monthly") booktypeStr = "Monthly";
      else booktypeStr = "Annually";
      _bookTypeInput->setCurrentText(booktypeStr);
    } else if (auto vinyl = dynamic_cast<Vinyl *>(product)) {
      _colorInput->setText(QString::fromStdString(vinyl->getColor()));
      _formatInput->setCurrentText(QString::fromStdString(vinyl->getFormatAsString()));
      _speedInput->setCurrentText(QString::fromStdString(vinyl->getSpeedAsString()));
    }
    if (auto movie = dynamic_cast<Movie *>(product)) {
      _directorInput->setText(QString::fromStdString(movie->getDirector()));
      _photoDirectorInput->setText(QString::fromStdString(movie->getPhotoDirector()));
      _protagonistInput->setText(QString::fromStdString(movie->getProtagonist()));
      _movieDurationInput->setText(QString::number(movie->getDuration()));
      _movieGenreInput->setText(QString::fromStdString(movie->getGenre()));
    }
  } else {
    QMessageBox::warning(this,
                         "Errore",
                         "Impossibile modificare l'elemento selezionato");
  }
}

void Window::onUndoClicked() {
  resetForm();
  _confirmButton->setDisabled(false);
  _viewButton->setDisabled(false);
  _deleteButton->setDisabled(false);
  _editButton->setDisabled(false);
  _importButton->setDisabled(false);
  _exportButton->setDisabled(false);
  _searchButton->setDisabled(false);
  _typeInput->setDisabled(false);
  _undoButton->hide();
  _confirmEditButton->hide();
}

void Window::onConfirmEditClicked() {
  if (indexInProductList >= 0) {
    Product *product = _productList[indexInProductList].get();
    if (!product) return;

    product->setName(_nameInput->text().toStdString());
    product->setPrice(_priceInput->text().toDouble());
    product->setTotalCopies(_copiesInput->text().toInt());
    product->setDate(QDateTime(_dateInput->dateTime()));

    product->setImage(_imageInput->text().toStdString());

    if (auto paperProduct = dynamic_cast<PaperProduct *>(product)) {
      paperProduct->setAuthor(_authorInput->text().toStdString());
      paperProduct->setPublisher(_editorInput->text().toStdString());
      paperProduct->setGenre(_paperProductGenreInput->text().toStdString());
      paperProduct->setPages(_pagesInput->text().toInt());
    }
    if (auto book = dynamic_cast<Book *>(product)) {
      book->setBinding(_bindingInput->text().toStdString());
      book->setLanguage(_languageInput->text().toStdString());
    } else if (auto magazine = dynamic_cast<Magazine *>(product)) {
      QString periodicityStr = _periodicityInput->currentText();
      Periodical::periodicalType periodicity;
      if (periodicityStr == "Daily") periodicity = Periodical::daily;
      else if (periodicityStr == "weekly") periodicity = Periodical::weekly;
      else if (periodicityStr == "monthly") periodicity = Periodical::monthly;
      else periodicity = Periodical::annually;
      magazine->setPeriodicity(periodicity);
      magazine->setTopic(_topicInput->text().toStdString());
    } else if (auto comic = dynamic_cast<Comic *>(product)) {
      QString periodicityStr = _periodicityInput->currentText();
      Periodical::periodicalType periodicity;
      if (periodicityStr == "Daily") periodicity = Periodical::daily;
      else if (periodicityStr == "Weekly") periodicity = Periodical::weekly;
      else if (periodicityStr == "Monthly") periodicity = Periodical::monthly;
      else periodicity = Periodical::annually;
      comic->setPeriodicity(periodicity);
      comic->setVolume(_volumeInput->text().toInt());
      comic->setEdition(_editionInput->text().toStdString());
    }
    if (auto disk = dynamic_cast<Disk *>(product)) {
      disk->setArtist(_artistInput->text().toStdString());
      disk->setPublisher(_publisherInput->text().toStdString());
      disk->setDuration(_diskDurationInput->text().toInt());
    }
    if (auto cd = dynamic_cast<CD *>(product)) {
      cd->setDiameter(_diameterInput->text().toInt());
      QString booktypeStr = _bookTypeInput->currentText();
      CD::BookType bookType;
      if (booktypeStr == "Red") bookType = CD::Red;
      else if (booktypeStr == "Yellow") bookType = CD::Yellow;
      else if (booktypeStr == "Orange") bookType = CD::Orange;
      else if (booktypeStr == "Green") bookType = CD::Green;
      else if (booktypeStr == "Blue") bookType = CD::Blue;
      else if (booktypeStr == "White") bookType = CD::White;
      cd->setBookType(bookType);
    } else if (auto vinyl = dynamic_cast<Vinyl *>(product)) {
      vinyl->setColor(_colorInput->text().toStdString());
      QString formatStr = _formatInput->currentText();
      Vinyl::FormatType format;
      if (formatStr == "12") format = Vinyl::Twelve;
      else if (formatStr == "10") format = Vinyl::Ten;
      else if (formatStr == "7") format = Vinyl::Seven;
      vinyl->setFormat(format);
      QString speedStr = _speedInput->currentText();
      Vinyl::SpeedType speed;
      if (speedStr == "33") speed = Vinyl::ThirtyThree;
      else if (speedStr == "45") speed = Vinyl::FortyFive;
      vinyl->setSpeed(speed);
    }
    if (auto movie = dynamic_cast<Movie *>(product)) {
      movie->setDirector(_directorInput->text().toStdString());
      movie->setPhotoDirector(_photoDirectorInput->text().toStdString());
      movie->setProtagonist(_protagonistInput->text().toStdString());
      movie->setDuration(_movieDurationInput->text().toInt());
      movie->setGenre(_movieGenreInput->text().toStdString());
    }
  }
  //MODIFICA FINITA E SI TORNA INDIETRO
  onUndoClicked();
  //MOSTRO TABELLA AGGIORNATA
  onViewClicked();
  indexInProductList = -1;
}
