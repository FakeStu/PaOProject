#include "XmlExportVisitor.h"

#include <QFile>

#include "../../../Model/Book.h"
#include "../../../Model/CD.h"
#include "../../../Model/Comic.h"
#include "../../../Model/Magazine.h"
#include "../../../Model/Movie.h"
#include "../../../Model/Vinyl.h"

XmlExportVisitor::XmlExportVisitor() {
  _doc = QDomDocument();

  const auto xmlDeclaration = _doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
  _doc.appendChild(xmlDeclaration);

  _root = _doc.createElement("products");
  _doc.appendChild(_root);
}

void XmlExportVisitor::addCommonElements(const Product &product, QDomElement &element) {
  QDomElement name = _doc.createElement("name");
  name.appendChild(_doc.createTextNode(QString::fromStdString(product.getName())));
  element.appendChild(name);

  QDomElement price = _doc.createElement("price");
  price.appendChild(_doc.createTextNode(QString::number(product.getPrice())));
  element.appendChild(price);

  QDomElement date = _doc.createElement("date");
  date.appendChild(_doc.createTextNode(product.getDate().toString(Qt::ISODate)));
  element.appendChild(date);

  QDomElement copies = _doc.createElement("availableCopies");
  copies.appendChild(_doc.createTextNode(QString::number(product.getTotalCopies())));
  element.appendChild(copies);

  QDomElement image = _doc.createElement("image");
  image.appendChild(_doc.createTextNode(QString::fromStdString(product.getImage())));
  element.appendChild(image);
}

void XmlExportVisitor::addPaperProductElements(const PaperProduct &paperProduct, QDomElement &element) {
  QDomElement author = _doc.createElement("author");
  author.appendChild(_doc.createTextNode(QString::fromStdString(paperProduct.getAuthor())));
  element.appendChild(author);

  QDomElement editor = _doc.createElement("editor");
  author.appendChild(_doc.createTextNode(QString::fromStdString(paperProduct.getPublisher())));
  element.appendChild(author);

  QDomElement genre = _doc.createElement("genre");
  author.appendChild(_doc.createTextNode(QString::fromStdString(paperProduct.getGenre())));
  element.appendChild(author);

  QDomElement pages = _doc.createElement("pages");
  author.appendChild(_doc.createTextNode((QString::number(paperProduct.getPages()))));
  element.appendChild(author);
}

void XmlExportVisitor::addPeriodicalProductElements(const Periodical &periodical, QDomElement &element) {
  QDomElement periodicity = _doc.createElement("periodicity");
  periodicity.appendChild(_doc.createTextNode(QString::fromStdString(periodical.getPeriodicityAsString())));
  element.appendChild(periodicity);
}

void XmlExportVisitor::addDiskElements(const Disk &disk, QDomElement &element) {
  QDomElement artist = _doc.createElement("artist");
  artist.appendChild(_doc.createTextNode(QString::fromStdString(disk.getArtist())));
  element.appendChild(artist);

  QDomElement publisher = _doc.createElement("publisher");
  publisher.appendChild(_doc.createTextNode(QString::fromStdString(disk.getPublisher())));
  element.appendChild(publisher);

  QDomElement duration = _doc.createElement("duration");
  duration.appendChild(_doc.createTextNode(QString::number(disk.getDuration())));
  element.appendChild(duration);
}

void XmlExportVisitor::visit(Book &book) {
  QDomElement element = _doc.createElement("book");

  addCommonElements(book, element);
  addPaperProductElements(book, element);

  QDomElement binding = _doc.createElement("binding");
  binding.appendChild(_doc.createTextNode(QString::fromStdString(book.getBinding())));
  element.appendChild(binding);

  QDomElement language = _doc.createElement("original_language");
  language.appendChild(_doc.createTextNode(QString::fromStdString(book.getLanguage())));
  element.appendChild(language);

  _root.appendChild(element);
}

void XmlExportVisitor::visit(Magazine &magazine) {
  QDomElement element = _doc.createElement("magazine");

  addCommonElements(magazine, element);
  addPaperProductElements(magazine, element);
  addPeriodicalProductElements(magazine, element);

  QDomElement topic = _doc.createElement("topic");
  topic.appendChild(_doc.createTextNode(QString::fromStdString(magazine.getTopic())));
  element.appendChild(topic);

  _root.appendChild(element);
}

void XmlExportVisitor::visit(Comic &comic) {
  QDomElement element = _doc.createElement("comic");

  addCommonElements(comic, element);
  addPaperProductElements(comic, element);
  addPeriodicalProductElements(comic, element);

  QDomElement volume = _doc.createElement("volume");
  volume.appendChild(_doc.createTextNode(QString::number(comic.getVolume())));
  element.appendChild(volume);

  QDomElement edition = _doc.createElement("edition");
  edition.appendChild(_doc.createTextNode(QString::fromStdString(comic.getEdition())));
  element.appendChild(edition);

  _root.appendChild(element);
}

void XmlExportVisitor::visit(CD &cd) {
  QDomElement element = _doc.createElement("cd");

  addCommonElements(cd, element);
  addDiskElements(cd, element);

  QDomElement diameter = _doc.createElement("diameter");
  diameter.appendChild(_doc.createTextNode(QString::number(cd.getDiameter())));
  element.appendChild(diameter);

  QDomElement bookType = _doc.createElement("bookType");
  bookType.appendChild(_doc.createTextNode(QString::fromStdString(cd.getBookTypeAsString())));
  element.appendChild(bookType);

  _root.appendChild(element);
}

void XmlExportVisitor::visit(Vinyl &vinyl) {
  QDomElement element = _doc.createElement("vinyl");

  addCommonElements(vinyl, element);
  addDiskElements(vinyl, element);

  QDomElement color = _doc.createElement("color");
  color.appendChild(_doc.createTextNode(QString::fromStdString(vinyl.getColor())));
  element.appendChild(color);

  QDomElement format = _doc.createElement("format");
  format.appendChild(_doc.createTextNode(QString::fromStdString(vinyl.getFormatAsString())));
  element.appendChild(format);

  QDomElement speed = _doc.createElement("speed");
  speed.appendChild(_doc.createTextNode(QString::fromStdString(vinyl.getSpeedAsString())));
  element.appendChild(speed);

  _root.appendChild(element);
}

void XmlExportVisitor::visit(Movie &movie) {
  QDomElement element = _doc.createElement("vinyl");

  addCommonElements(movie, element);

  QDomElement director = _doc.createElement("director");
  director.appendChild(_doc.createTextNode(QString::fromStdString(movie.getDirector())));
  element.appendChild(director);

  QDomElement photoDirector = _doc.createElement("photoDirector");
  photoDirector.appendChild(_doc.createTextNode(QString::fromStdString(movie.getPhotoDirector())));
  element.appendChild(photoDirector);

  QDomElement protagonist = _doc.createElement("protagonist");
  protagonist.appendChild(_doc.createTextNode(QString::fromStdString(movie.getProtagonist())));
  element.appendChild(protagonist);

  QDomElement duration = _doc.createElement("duration");
  duration.appendChild(_doc.createTextNode(QString::number(movie.getDuration())));
  element.appendChild(duration);

  QDomElement genre = _doc.createElement("genre");
  genre.appendChild(_doc.createTextNode(QString::fromStdString(movie.getGenre())));
  element.appendChild(genre);

  _root.appendChild(element);
}

void XmlExportVisitor::exportToFile(const QString &filename, const std::vector<std::shared_ptr<Product> > &products) {
  // Add the products to the root object
  for (const auto &product: products) {
    product->accept(*this);
  }

  QFile file(filename);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    throw std::runtime_error("Cannot open file for writing");
  }

  QTextStream stream(&file);
  stream << _doc.toString();
  file.close();

  _doc.clear();
  _root = _doc.createElement("products");
  _doc.appendChild(_root);
}
