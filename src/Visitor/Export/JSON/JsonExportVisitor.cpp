#include "JsonExportVisitor.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include "..\..\..\Model\Book.h"
#include "..\..\..\Model\CD.h"
#include "..\..\..\Model\Comic.h"
#include "..\..\..\Model\Magazine.h"
#include "..\..\..\Model\Movie.h"
#include "..\..\..\Model\Vinyl.h"

void JsonExportVisitor::visit(Book &book) {
  QJsonObject bookJson;
  bookJson["type"] = "Book";
  bookJson["name"] = QString::fromStdString(book.getName());
  bookJson["price"] = book.getPrice();
  bookJson["date"] = book.getDate().toString(Qt::ISODate);
  bookJson["totalCopies"] = book.getTotalCopies();
  bookJson["image"] = QString::fromStdString(book.getImage());
  bookJson["author"] = QString::fromStdString(book.getAuthor());
  bookJson["editor"] = QString::fromStdString(book.getEditor());
  bookJson["genre"] = QString::fromStdString(book.getGenre());
  bookJson["pages"] = book.getPages();
  bookJson["binding"] = QString::fromStdString(book.getBinding());
  bookJson["original_language"] = QString::fromStdString(book.getLanguage());
  products.append(bookJson);
}

void JsonExportVisitor::visit(CD &cd) {
  QJsonObject cdJson;
  cdJson["type"] = "CD";
  cdJson["name"] = QString::fromStdString(cd.getName());
  cdJson["price"] = cd.getPrice();
  cdJson["date"] = cd.getDate().toString(Qt::ISODate);
  cdJson["totalCopies"] = cd.getTotalCopies();
  cdJson["image"] = QString::fromStdString(cd.getImage());
  cdJson["artist"] = QString::fromStdString(cd.getArtist());
  cdJson["duration"] = cd.getDuration();
  products.append(cdJson);
}

void JsonExportVisitor::visit(Magazine &magazine) {
  QJsonObject magazineJson;
  magazineJson["type"] = "Magazine";
  magazineJson["name"] = QString::fromStdString(magazine.getName());
  magazineJson["price"] = magazine.getPrice();
  magazineJson["date"] = magazine.getDate().toString(Qt::ISODate);
  magazineJson["totalCopies"] = magazine.getTotalCopies();
  magazineJson["image"] = QString::fromStdString(magazine.getImage());
  magazineJson["author"] = QString::fromStdString(magazine.getAuthor());
  magazineJson["editor"] = QString::fromStdString(magazine.getEditor());
  magazineJson["genre"] = QString::fromStdString(magazine.getGenre());
  magazineJson["pages"] = magazine.getPages();
  products.append(magazineJson);
}

void JsonExportVisitor::visit(Comic &comic) {
  QJsonObject comicJson;
  comicJson["type"] = "Comic";
  comicJson["name"] = QString::fromStdString(comic.getName());
  comicJson["price"] = comic.getPrice();
  comicJson["date"] = comic.getDate().toString(Qt::ISODate);
  comicJson["totalCopies"] = comic.getTotalCopies();
  comicJson["image"] = QString::fromStdString(comic.getImage());
  comicJson["author"] = QString::fromStdString(comic.getAuthor());
  comicJson["editor"] = QString::fromStdString(comic.getEditor());
  comicJson["genre"] = QString::fromStdString(comic.getGenre());
  comicJson["pages"] = comic.getPages();
  products.append(comicJson);
}

void JsonExportVisitor::visit(Vinyl &vinyl) {
  QJsonObject vinylJson;
  vinylJson["type"] = "Vinyl";
  vinylJson["name"] = QString::fromStdString(vinyl.getName());
  vinylJson["price"] = vinyl.getPrice();
  vinylJson["date"] = vinyl.getDate().toString(Qt::ISODate);
  vinylJson["totalCopies"] = vinyl.getTotalCopies();
  vinylJson["image"] = QString::fromStdString(vinyl.getImage());
  vinylJson["artist"] = QString::fromStdString(vinyl.getArtist());
  vinylJson["duration"] = vinyl.getDuration();
  products.append(vinylJson);
}

void JsonExportVisitor::visit(Movie &movie) {
  QJsonObject movieJson;
  movieJson["type"] = "Movie";
  movieJson["name"] = QString::fromStdString(movie.getName());
  movieJson["price"] = movie.getPrice();
  movieJson["date"] = movie.getDate().toString(Qt::ISODate);
  movieJson["totalCopies"] = movie.getTotalCopies();
  movieJson["image"] = QString::fromStdString(movie.getImage());
  movieJson["duration"] = movie.getDuration();
  products.append(movieJson);
}

void JsonExportVisitor::exportToFile(const std::string &filename) {
  QJsonObject root;
  root["products"] = products;

  QJsonDocument doc(root);
  QFile file(QString::fromStdString(filename));
  if (file.open(QIODevice::WriteOnly)) {
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
  }
  products = QJsonArray();
}
