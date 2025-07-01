#include "JsonExportVisitor.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include "../../../Model/Book.h"
#include "../../../Model/CD.h"
#include "../../../Model/Comic.h"
#include "../../../Model/Magazine.h"
#include "../../../Model/Movie.h"
#include "../../../Model/Vinyl.h"

void JsonExportVisitor::addCommonElements(const Product &product, QJsonObject &element) {
  element["name"] = QString::fromStdString(product.getName());
  element["price"] = product.getPrice();
  element["date"] = product.getDate().toString(Qt::ISODate);
  element["availableCopies"] = product.getTotalCopies();
  element["image"] = QString::fromStdString(product.getImage());
}

void JsonExportVisitor::addPaperProductElements(const PaperProduct &paperProduct, QJsonObject &element) {
  element["author"] = QString::fromStdString(paperProduct.getAuthor());
  element["editor"] = QString::fromStdString(paperProduct.getPublisher());
  element["genre"] = QString::fromStdString(paperProduct.getGenre());
  element["pages"] = paperProduct.getPages();
}

void JsonExportVisitor::addPeriodicalProductElements(const Periodical &periodical, QJsonObject &element) {
  element[" periodicity"] = QString::fromStdString(periodical.getPeriodicityAsString());
}

void JsonExportVisitor::addDiskElements(const Disk &disk, QJsonObject &element) {
  element["artist"] = QString::fromStdString(disk.getArtist());
  element["publisher"] = QString::fromStdString(disk.getPublisher());
  element["duration"] = disk.getDuration();
}

void JsonExportVisitor::visit(Book &book) {
  QJsonObject element;

  addCommonElements(book, element);
  addPaperProductElements(book, element);

  element["binding"] = QString::fromStdString(book.getBinding());
  element["original_language"] = QString::fromStdString(book.getLanguage());

  QJsonArray array = products["book"].toArray();
  array.append(element);
  products["book"] = array;
}

void JsonExportVisitor::visit(Magazine &magazine) {
  QJsonObject element;

  addCommonElements(magazine, element);
  addPaperProductElements(magazine, element);
  addPeriodicalProductElements(magazine, element);

  element["topic"] = QString::fromStdString(magazine.getTopic());

  QJsonArray array = products["magazine"].toArray();
  array.append(element);
  products["magazine"] = array;
}

void JsonExportVisitor::visit(Comic &comic) {
  QJsonObject element;

  addCommonElements(comic, element);
  addPaperProductElements(comic, element);
  addPeriodicalProductElements(comic, element);

  element["volume"] = comic.getVolume();
  element["edition"] = QString::fromStdString(comic.getEdition());

  QJsonArray array = products["comic"].toArray();
  array.append(element);
  products["comic"] = array;
}

void JsonExportVisitor::visit(CD &cd) {
  QJsonObject element;

  addCommonElements(cd, element);
  addDiskElements(cd, element);

  element["diameter"] = cd.getDiameter();
  element["bookType"] = QString::fromStdString(cd.getBookTypeAsString());

  QJsonArray array = products["cd"].toArray();
  array.append(element);
  products["cd"] = array;
}

void JsonExportVisitor::visit(Vinyl &vinyl) {
  QJsonObject element;

  addCommonElements(vinyl, element);
  addDiskElements(vinyl, element);

  element["color"] = QString::fromStdString(vinyl.getColor());
  element["format"] = QString::fromStdString(vinyl.getFormatAsString());
  element["speed"] = QString::fromStdString(vinyl.getSpeedAsString());

  QJsonArray array = products["vinyl"].toArray();
  array.append(element);
  products["vinyl"] = array;
}

void JsonExportVisitor::visit(Movie &movie) {
  QJsonObject element;

  addCommonElements(movie, element);

  element["director"] = QString::fromStdString(movie.getDirector());
  element["photoDirector"] = QString::fromStdString(movie.getPhotoDirector());
  element["protagonist"] = QString::fromStdString(movie.getProtagonist());
  element["duration"] = movie.getDuration();
  element["genre"] = QString::fromStdString(movie.getGenre());

  QJsonArray array = products["movie"].toArray();
  array.append(element);
  products["movie"] = array;
}

void JsonExportVisitor::exportToFile(const QString &filename, const std::vector<std::shared_ptr<Product> > &products) {
  QJsonObject root;

  // Add the products to the root object
  for (const auto &product: products) {
    product->accept(*this);
  }

  // Add the root object to the JSON document
  root["products"] = this->products;
  const QJsonDocument doc(root);

  QFile file(filename);
  if (!file.open(QIODevice::WriteOnly)) {
    throw std::runtime_error("Cannot open file for writing");
  }

  file.write(doc.toJson(QJsonDocument::Indented));
  file.close();

  this->products = QJsonObject();
}
