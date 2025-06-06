#include "ProductFormPage.h"

#include <QHeaderView>

ProductFormPage::ProductFormPage(QWidget *parent) : QWidget(parent) {
    QFormLayout* mainLayout = new QFormLayout(this);

    typeCombo = new QComboBox(this);
    typeCombo->addItems({"Book", "CD", "Magazine", "Comic", "Vinyl", "Film"});
    connect(typeCombo, &QComboBox::currentTextChanged, this, &ProductFormPage::onTypeChanged);

    // Comuni
    nameEdit = new QLineEdit(this);
    priceEdit = new QLineEdit(this);
    copiesEdit = new QLineEdit(this);
    dateEdit = new QDateEdit(QDate::currentDate(), this);
    dateEdit->setCalendarPopup(true);
    imageEdit = new QLineEdit(this);

    mainLayout->addRow("Tipo:", typeCombo);
    mainLayout->addRow("Nome:", nameEdit);
    mainLayout->addRow("Prezzo:", priceEdit);
    mainLayout->addRow("Copie:", copiesEdit);
    mainLayout->addRow("Data:", dateEdit);
    mainLayout->addRow("Immagine:", imageEdit);

    specificStack = new QStackedWidget(this);

    // Book Widget
    bookWidget = new QWidget(this);
    QFormLayout* bookLayout = new QFormLayout(bookWidget);
    authorEdit = new QLineEdit(this);
    editorEdit = new QLineEdit(this);
    pagesEdit = new QLineEdit(this);
    genreEdit = new QLineEdit(this);
    bindingEdit = new QLineEdit(this);
    languageEdit = new QLineEdit(this);
    bookLayout->addRow("Autore:", authorEdit);
    bookLayout->addRow("Editore:", editorEdit);
    bookLayout->addRow("Pagine:", pagesEdit);
    bookLayout->addRow("Genere:", genreEdit);
    bookLayout->addRow("Rilegatura:", bindingEdit);
    bookLayout->addRow("Lingua Originale:", languageEdit);
    specificStack->addWidget(bookWidget);

    // CD Widget
    cdWidget = new QWidget(this);
    QFormLayout* cdLayout = new QFormLayout(cdWidget);
    artistEdit = new QLineEdit(this);
    publisherEdit = new QLineEdit(this);
    durationEdit = new QLineEdit(this);
    bookTypeCombo = new QComboBox(this);
    bookTypeCombo->addItems({"Red", "Yellow", "Orange", "Green", "White", "Blue"});
    diameterEdit = new QLineEdit(this);
    versionEdit = new QLineEdit(this);
    cdLayout->addRow("Artista:", artistEdit);
    cdLayout->addRow("Editore:", publisherEdit);
    cdLayout->addRow("Durata:", durationEdit);
    cdLayout->addRow("Tipo:", bookTypeCombo);
    cdLayout->addRow("Diametro:", diameterEdit);
    cdLayout->addRow("Versione:", versionEdit);
    specificStack->addWidget(cdWidget);

    // Magazine Widget
    magazineWidget = new QWidget(this);
    QFormLayout* magLayout = new QFormLayout(magazineWidget);
    magAuthorEdit = new QLineEdit(this);
    magEditorEdit = new QLineEdit(this);
    magGenreEdit = new QLineEdit(this);
    magPagesEdit = new QLineEdit(this);
    magPeriodicityCombo = new QComboBox(this);
    magPeriodicityCombo->addItems({"Daily", "Weekly", "Monthly", "Annually"});
    magTopicEdit = new QLineEdit(this);
    magLayout->addRow("Autore:", magAuthorEdit);
    magLayout->addRow("Editore:", magEditorEdit);
    magLayout->addRow("Genere:", magGenreEdit);
    magLayout->addRow("Pagine:", magPagesEdit);
    magLayout->addRow("Periodicità:", magPeriodicityCombo);
    magLayout->addRow("Topic:", magTopicEdit);
    specificStack->addWidget(magazineWidget);

    // Comic Widget
    comicWidget = new QWidget(this);
    QFormLayout* comicLayout = new QFormLayout(comicWidget);
    comicAuthorEdit = new QLineEdit(this);
    comicEditorEdit = new QLineEdit(this);
    comicGenreEdit = new QLineEdit(this);
    comicPagesEdit = new QLineEdit(this);
    comicPeriodicityCombo = new QComboBox(this);
    comicPeriodicityCombo->addItems({"Daily", "Weekly", "Monthly", "Annually"});
    comicVolumeEdit = new QLineEdit(this);
    comicEditionEdit = new QLineEdit(this);
    comicLayout->addRow("Autore:", comicAuthorEdit);
    comicLayout->addRow("Editore:", comicEditorEdit);
    comicLayout->addRow("Genere:", comicGenreEdit);
    comicLayout->addRow("Pagine:", comicPagesEdit);
    comicLayout->addRow("Periodicità:", comicPeriodicityCombo);
    comicLayout->addRow("Volume:", comicVolumeEdit);
    comicLayout->addRow("Edizione:", comicEditionEdit);
    specificStack->addWidget(comicWidget);

    // Vinyl
    vinylWidget = new QWidget(this);
    QFormLayout* vinylLayout = new QFormLayout(vinylWidget);

    vinylArtistEdit = new QLineEdit(this);
    vinylPublisherEdit = new QLineEdit(this);
    vinylDurationEdit = new QLineEdit(this);

    vinylFormatCombo = new QComboBox(this);
    vinylFormatCombo->addItems({"12", "10", "7"});

    vinylSpeedCombo = new QComboBox(this);
    vinylSpeedCombo->addItems({"33", "45"});

    vinylColorEdit = new QLineEdit(this);

    vinylLayout->addRow("Artista:", vinylArtistEdit);
    vinylLayout->addRow("Editore:", vinylPublisherEdit);
    vinylLayout->addRow("Durata:", vinylDurationEdit);
    vinylLayout->addRow("Formato:", vinylFormatCombo);
    vinylLayout->addRow("Velocità:", vinylSpeedCombo);
    vinylLayout->addRow("Colore:", vinylColorEdit);

    specificStack->addWidget(vinylWidget);

    // Film
    filmWidget = new QWidget(this);
    QFormLayout* filmLayout = new QFormLayout(filmWidget);

    filmDirectorEdit = new QLineEdit(this);
    filmPhotoDirectorEdit = new QLineEdit(this);
    filmProtagonistEdit = new QLineEdit(this);
    filmDurationEdit = new QLineEdit(this);
    filmGenreEdit = new QLineEdit(this);

    filmLayout->addRow("Regista:", filmDirectorEdit);
    filmLayout->addRow("Direttore Fotografia:", filmPhotoDirectorEdit);
    filmLayout->addRow("Protagonista:", filmProtagonistEdit);
    filmLayout->addRow("Durata (min):", filmDurationEdit);
    filmLayout->addRow("Genere:", filmGenreEdit);

    specificStack->addWidget(filmWidget);

    mainLayout->addRow(specificStack);

    confirmButton = new QPushButton("Aggiungi", this);
    connect(confirmButton, &QPushButton::clicked, this, &ProductFormPage::onConfirmClicked);
    mainLayout->addRow(confirmButton);

    viewButton = new QPushButton("Visualizza", this);
    mainLayout->addRow(viewButton);
    connect(viewButton, &QPushButton::clicked, this, &ProductFormPage::onViewClicked);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(5);
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    mainLayout->addWidget(tableWidget);

    onTypeChanged("Book");
}


void ProductFormPage::resetForm() {
    // Comuni
    nameEdit->clear();
    priceEdit->clear();
    copiesEdit->clear();
    imageEdit->clear();
    dateEdit->setDate(QDate::currentDate());

    // Book
    authorEdit->clear();
    editorEdit->clear();
    genreEdit->clear();
    pagesEdit->clear();
    bindingEdit->clear();
    languageEdit->clear();

    // CD
    artistEdit->clear();
    publisherEdit->clear();
    durationEdit->clear();
    diameterEdit->clear();
    versionEdit->clear();
    bookTypeCombo->setCurrentIndex(0);

    // Magazine
    magAuthorEdit->clear();
    magEditorEdit->clear();
    magGenreEdit->clear();
    magPagesEdit->clear();
    magPeriodicityCombo->setCurrentIndex(0);
    magTopicEdit->clear();

    // Comic
    comicAuthorEdit->clear();
    comicEditorEdit->clear();
    comicGenreEdit->clear();
    comicPagesEdit->clear();
    comicPeriodicityCombo->setCurrentIndex(0);
    comicVolumeEdit->clear();
    comicEditionEdit->clear();

    //Vinyl
    vinylArtistEdit->clear();
    vinylPublisherEdit->clear();
    vinylDurationEdit->clear();
    vinylFormatCombo->setCurrentIndex(0);
    vinylSpeedCombo->setCurrentIndex(0);
    vinylColorEdit->clear();

    //Film
    filmDirectorEdit->clear();
    filmPhotoDirectorEdit->clear();
    filmProtagonistEdit->clear();
    filmDurationEdit->clear();
    filmGenreEdit->clear();
}

void ProductFormPage::onTypeChanged(const QString &type) {
    if (type == "Book") specificStack->setCurrentWidget(bookWidget);
    else if (type == "CD") specificStack->setCurrentWidget(cdWidget);
    else if (type == "Magazine") specificStack->setCurrentWidget(magazineWidget);
    else if (type == "Comic") specificStack->setCurrentWidget(comicWidget);
    else if (type == "Vinyl") specificStack->setCurrentWidget(vinylWidget);
    else if (type == "Film") specificStack->setCurrentWidget(filmWidget);

}


void ProductFormPage::onConfirmClicked() {
    QString type = typeCombo->currentText();

    // Campi comuni
    std::string name = nameEdit->text().toStdString();
    double price = priceEdit->text().toDouble();
    QDateTime date = dateEdit->dateTime();
    int copies = copiesEdit->text().toInt();
    std::string image = imageEdit->text().toStdString();

    if (name.empty()) {
        QMessageBox::warning(this, "Errore", "Manca il campo Nome");
        return;
    }

    if (type == "Book") {
        std::string author = authorEdit->text().toStdString();
        if (author.empty()) {
            QMessageBox::warning(this, "Errore", "Manca il campo Autore");
            return;
        }
        std::string editor = editorEdit->text().toStdString();
        std::string genre = genreEdit->text().toStdString();
        int pages = pagesEdit->text().toInt();
        std::string binding = bindingEdit->text().toStdString();
        std::string language = languageEdit->text().toStdString();

        std::shared_ptr<Book> newBook = std::make_shared<Book>(
            name, price, date, copies, image, author, editor, genre, pages, binding, language);

        productList.push_back(newBook);
        QMessageBox::information(this, "Successo", "Libro aggiunto con successo");

    } else if (type == "CD") {
        std::string artist = artistEdit->text().toStdString();
        std::string publisher = publisherEdit->text().toStdString();
        int duration = durationEdit->text().toInt();
        int diameter = diameterEdit->text().toInt();
        std::string version = versionEdit->text().toStdString();

        QString typeStr = bookTypeCombo->currentText();
        CD::BookType bookType;
        if (typeStr == "Red") bookType = CD::Red;
        else if (typeStr == "Yellow") bookType = CD::Yellow;
        else if (typeStr == "Orange") bookType = CD::Orange;
        else if (typeStr == "Green") bookType = CD::Green;
        else if (typeStr == "White") bookType = CD::White;
        else bookType = CD::Blue;

        std::shared_ptr<CD> newCD = std::make_shared<CD>(
            name, price, date, copies, image,
            artist, publisher, duration, diameter, bookType);

        productList.push_back(newCD);
        QMessageBox::information(this, "Successo", "CD aggiunto con successo");

    } else if (type == "Magazine") {
        std::string author = magAuthorEdit->text().toStdString();
        if (author.empty()) {
            QMessageBox::warning(this, "Errore", "Manca il campo Autore");
            return;
        }
        std::string editor = magEditorEdit->text().toStdString();
        std::string genre = magGenreEdit->text().toStdString();
        int pages = magPagesEdit->text().toInt();
        QString perStr = magPeriodicityCombo->currentText();
        Periodical::periodicalType periodicity;
        if (perStr == "Daily") periodicity = Periodical::daily;
        else if (perStr == "Weekly") periodicity = Periodical::weekly;
        else if (perStr == "Monthly") periodicity = Periodical::monthly;
        else periodicity = Periodical::annualy;
        std::string topic = magTopicEdit->text().toStdString();

        std::shared_ptr<Magazine> newMagazine = std::make_shared<Magazine>(
            name, price, date, copies, image,
            author, editor, genre, pages, periodicity, topic);

        productList.push_back(newMagazine);
        QMessageBox::information(this, "Successo", "Magazine aggiunto con successo");

    } else if (type == "Comic") {
        std::string author = comicAuthorEdit->text().toStdString();
        if (author.empty()) {
            QMessageBox::warning(this, "Errore", "Manca il campo Autore");
            return;
        }
        std::string editor = comicEditorEdit->text().toStdString();
        std::string genre = comicGenreEdit->text().toStdString();
        int pages = comicPagesEdit->text().toInt();
        QString perStr = comicPeriodicityCombo->currentText();
        Periodical::periodicalType periodicity;
        if (perStr == "Daily") periodicity = Periodical::daily;
        else if (perStr == "Weekly") periodicity = Periodical::weekly;
        else if (perStr == "Monthly") periodicity = Periodical::monthly;
        else periodicity = Periodical::annualy;
        int volume = comicVolumeEdit->text().toInt();
        std::string edition = comicEditionEdit->text().toStdString();

        std::shared_ptr<Comic> newComic = std::make_shared<Comic>(
            name, price, date, copies, image,
            author, editor, genre, pages, periodicity, volume, edition);

        productList.push_back(newComic);
        QMessageBox::information(this, "Successo", "Comic aggiunto con successo");
    }
    else if (type == "Vinyl") {
        std::string artist = vinylArtistEdit->text().toStdString();
        std::string publisher = vinylPublisherEdit->text().toStdString();
        int duration = vinylDurationEdit->text().toInt();
        int formatInt = vinylFormatCombo->currentText().toInt();
        Vinyl::FormatType format;
        switch (formatInt) {
            case 12: format = Vinyl::FormatType::Twelve; break;
            case 10: format = Vinyl::FormatType::Ten; break;
            case 7:  format = Vinyl::FormatType::Seven; break;
            default: format = Vinyl::FormatType::Twelve; // default
        }
        int speedInt = vinylSpeedCombo->currentText().toInt();
        Vinyl::SpeedType speed = (speedInt == 33) ? Vinyl::SpeedType::ThirtyThree : Vinyl::SpeedType::FortyFive;
        std::string color = vinylColorEdit->text().toStdString();

        std::shared_ptr<Vinyl> newVinyl = std::make_shared<Vinyl>(
            name, price, date, copies, image,
            artist, publisher, duration, color, format, speed
        );
        productList.push_back(newVinyl);
        QMessageBox::information(this, "Successo", "Vinyl aggiunto con successo");
    }
    else if (type == "Film") {
        std::string director = filmDirectorEdit->text().toStdString();
        std::string photoDirector = filmPhotoDirectorEdit->text().toStdString();
        std::string protagonist = filmProtagonistEdit->text().toStdString();
        int duration = filmDurationEdit->text().toInt();
        std::string genre = filmGenreEdit->text().toStdString();

        std::shared_ptr<Movie> newFilm = std::make_shared<Movie>(
            name, price, date, copies, image,
            director, photoDirector, protagonist, duration, genre
        );
        productList.push_back(newFilm);
        QMessageBox::information(this, "Successo", "Film aggiunto con successo");
    }


    resetForm();
}


void ProductFormPage::onViewClicked() {
    QString selected = typeCombo->currentText();

    tableWidget->clear();
    tableWidget->setRowCount(0);

    if (selected == "Book") {
        tableWidget->setColumnCount(5);
        tableWidget->setHorizontalHeaderLabels({"Nome", "Autore", "Prezzo", "Copie", "Lingua"});

        int row = 0;
        for (const auto& product : productList) {
            auto book = std::dynamic_pointer_cast<Book>(product);
            if (book) {
                tableWidget->insertRow(row);
                tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(book->getName())));
                tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(book->getAuthor())));
                tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(book->getPrice())));
                tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(book->getTotalCopies())));
                tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(book->getLanguage())));
                ++row;
            }
        }
    } else if (selected == "CD") {
        tableWidget->setColumnCount(5);
        tableWidget->setHorizontalHeaderLabels({"Nome", "Artista", "Prezzo", "Copie", "Durata"});

        int row = 0;
        for (const auto& product : productList) {
            auto cd = std::dynamic_pointer_cast<CD>(product);
            if (cd) {
                tableWidget->insertRow(row);
                tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(cd->getName())));
                tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(cd->getArtist())));
                tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(cd->getPrice())));
                tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(cd->getTotalCopies())));
                tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(cd->getDuration())));
                ++row;
            }
        }
    } else if (selected == "Magazine") {
        tableWidget->setColumnCount(6);
        tableWidget->setHorizontalHeaderLabels({"Nome", "Autore", "Prezzo", "Copie", "Periodicità", "Topic"});

        int row = 0;
        for (const auto& product : productList) {
            auto mag = std::dynamic_pointer_cast<Magazine>(product);
            if (mag) {
                tableWidget->insertRow(row);
                tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(mag->getName())));
                tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(mag->getAuthor())));
                tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(mag->getPrice())));
                tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(mag->getTotalCopies())));

                QString periodicityStr;
                QString p = QString::fromStdString(mag->getPeriodicity());

                if (p == "daily") periodicityStr = "Daily";
                else if (p == "weekly") periodicityStr = "Weekly";
                else if (p == "monthly") periodicityStr = "Monthly";
                else if (p == "annualy") periodicityStr = "Annually";
                else periodicityStr = "Unknown";


                tableWidget->setItem(row, 4, new QTableWidgetItem(periodicityStr));
                tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(mag->getTopic())));
                ++row;
            }
        }
    } else if (selected == "Comic") {
        tableWidget->setColumnCount(7);
        tableWidget->setHorizontalHeaderLabels({"Nome", "Autore", "Prezzo", "Copie", "Periodicità", "Volume", "Edizione"});

        int row = 0;
        for (const auto& product : productList) {
            auto comic = std::dynamic_pointer_cast<Comic>(product);
            if (comic) {
                tableWidget->insertRow(row);
                tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(comic->getName())));
                tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(comic->getAuthor())));
                tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(comic->getPrice())));
                tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(comic->getTotalCopies())));

                QString periodicityStr;
                QString p = QString::fromStdString(comic->getPeriodicity());

                if (p == "daily") periodicityStr = "Daily";
                else if (p == "weekly") periodicityStr = "Weekly";
                else if (p == "monthly") periodicityStr = "Monthly";
                else if (p == "annualy") periodicityStr = "Annually";
                else periodicityStr = "Unknown";

                tableWidget->setItem(row, 4, new QTableWidgetItem(periodicityStr));
                tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(comic->getVolume())));
                tableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(comic->getEdition())));
                ++row;
            }
        }
    }else if (selected == "Vinyl") {
        tableWidget->setColumnCount(7);
        tableWidget->setHorizontalHeaderLabels({"Nome", "Artista", "Editore", "Durata", "Formato", "Velocità", "Colore"});

        int row = 0;
        for (const auto& product : productList) {
            auto vinyl = std::dynamic_pointer_cast<Vinyl>(product);
            if (vinyl) {
                tableWidget->insertRow(row);
                tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(vinyl->getName())));
                tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(vinyl->getArtist())));
                tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(vinyl->getPublisher())));
                tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(vinyl->getDuration())));
                tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(vinyl->getFormatAsString())));
                tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(vinyl->getSpeedAsString())));
                tableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(vinyl->getColor())));
                ++row;
            }
        }

    } else if (selected == "Film") {
        tableWidget->setColumnCount(6);
        tableWidget->setHorizontalHeaderLabels({"Nome", "Regista", "Direttore Foto", "Protagonista", "Durata", "Genere"});

        int row = 0;
        for (const auto& product : productList) {
            auto film = std::dynamic_pointer_cast<Movie>(product);
            if (film) {
                tableWidget->insertRow(row);
                tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(film->getName())));
                tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(film->getDirector())));
                tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(film->getPhotoDirector())));
                tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(film->getProtagonist())));
                tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(film->getDuration())));
                tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(film->getGenre())));
                ++row;
            }
        }
    }
}
