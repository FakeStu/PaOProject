//
// Created by tuoni on 29/06/2025.
//

#include "XmlImport.h"

#include <iostream>
#include <QDateTime>
#include <QFile>
#include "..\..\..\Model\Book.h"
#include "..\..\..\Model\CD.h"
#include "..\..\..\Model\Comic.h"
#include "..\..\..\Model\Magazine.h"
#include "..\..\..\Model\Movie.h"
#include "..\..\..\Model\Vinyl.h"

std::shared_ptr<Product> XmlImport::createFromXml(const QDomElement &obj, const QString &type) {
  if (type == "book") return createBook(obj);
  if (type == "magazine") return createMagazine(obj);
  if (type == "comic") return createComic(obj);
  if (type == "cd") return createCD(obj);
  if (type == "vinyl") return createVinyl(obj);
  if (type == "movie") return createMovie(obj);

  return nullptr;
}

std::shared_ptr<Book> XmlImport::createBook(const QDomElement &obj) {
  return std::make_shared<Book>(obj.firstChildElement("name").text().toStdString(),
                                obj.firstChildElement("price").text().toDouble(),
                                QDateTime::fromString(obj.firstChildElement("date").text(), Qt::ISODate),
                                obj.firstChildElement("availableCopies").text().toInt(),
                                obj.firstChildElement("image").text().toStdString(),
                                obj.firstChildElement("author").text().toStdString(),
                                obj.firstChildElement("editor").text().toStdString(),
                                obj.firstChildElement("genre").text().toStdString(),
                                obj.firstChildElement("pages").text().toInt(),
                                obj.firstChildElement("binding").text().toStdString(),
                                obj.firstChildElement("language").text().toStdString()
                               );
}

std::shared_ptr<Magazine> XmlImport::createMagazine(const QDomElement &obj) {
  Magazine::periodicalType periodicity = Periodical::annually;
  QString typeStr = obj.firstChildElement("periodicity").text();
  if (typeStr == "daily") periodicity = Periodical::daily;
  else if (typeStr == "weekly") periodicity = Periodical::weekly;
  else if (typeStr == "monthly") periodicity = Periodical::monthly;
  else if (typeStr == "annually") periodicity = Periodical::annually;

  return std::make_shared<Magazine>(obj.firstChildElement("name").text().toStdString(),
                                obj.firstChildElement("price").text().toDouble(),
                                QDateTime::fromString(obj.firstChildElement("date").text(), Qt::ISODate),
                                obj.firstChildElement("availableCopies").text().toInt(),
                                obj.firstChildElement("image").text().toStdString(),
                                obj.firstChildElement("author").text().toStdString(),
                                obj.firstChildElement("editor").text().toStdString(),
                                obj.firstChildElement("genre").text().toStdString(),
                                obj.firstChildElement("pages").text().toInt(),
                                periodicity,
                                obj.firstChildElement("topic").text().toStdString()
                               );
}

std::shared_ptr<Comic> XmlImport::createComic(const QDomElement &obj) {
  Magazine::periodicalType periodicity = Periodical::annually;
  QString typeStr = obj.firstChildElement("periodicity").text();
  if (typeStr == "daily") periodicity = Periodical::daily;
  else if (typeStr == "weekly") periodicity = Periodical::weekly;
  else if (typeStr == "monthly") periodicity = Periodical::monthly;
  else if (typeStr == "annually") periodicity = Periodical::annually;

  return std::make_shared<Comic>(obj.firstChildElement("name").text().toStdString(),
                              obj.firstChildElement("price").text().toDouble(),
                              QDateTime::fromString(obj.firstChildElement("date").text(), Qt::ISODate),
                              obj.firstChildElement("availableCopies").text().toInt(),
                              obj.firstChildElement("image").text().toStdString(),
                              obj.firstChildElement("author").text().toStdString(),
                              obj.firstChildElement("editor").text().toStdString(),
                              obj.firstChildElement("genre").text().toStdString(),
                              obj.firstChildElement("pages").text().toInt(),
                              periodicity,
                              obj.firstChildElement("volume").text().toInt(),
                              obj.firstChildElement("edition").text().toStdString()
                             );
}

std::shared_ptr<CD> XmlImport::createCD(const QDomElement &obj) {
  CD::BookType bookType = CD::Red;
  QString typeStr = obj.firstChildElement("bookType").text();
  if (typeStr == "Red") bookType = CD::Red;
  else if (typeStr == "Yellow") bookType = CD::Yellow;
  else if (typeStr == "Orange") bookType = CD::Orange;
  else if (typeStr == "Green") bookType = CD::Green;
  else if (typeStr == "White") bookType = CD::White;
  else bookType = CD::Blue;

  return std::make_shared<CD>(obj.firstChildElement("name").text().toStdString(),
                              obj.firstChildElement("price").text().toDouble(),
                              QDateTime::fromString(obj.firstChildElement("date").text(), Qt::ISODate),
                              obj.firstChildElement("availableCopies").text().toInt(),
                              obj.firstChildElement("image").text().toStdString(),
                              obj.firstChildElement("artist").text().toStdString(),
                              obj.firstChildElement("publisher").text().toStdString(),
                              obj.firstChildElement("duration").text().toInt(),
                              obj.firstChildElement("diameter").text().toInt(),
                              bookType
                             );
}

std::shared_ptr<Vinyl> XmlImport::createVinyl(const QDomElement &obj) {
  Vinyl::FormatType format = Vinyl::Twelve;
  Vinyl::SpeedType speed = Vinyl::ThirtyThree;

  QString typeStr = obj.firstChildElement("format").text();
  if (typeStr == "12") format = Vinyl::Twelve;
  else if (typeStr == "10") format = Vinyl::Ten;
  else if (typeStr == "7") format = Vinyl::Seven;

  typeStr = obj.firstChildElement("speed").text();
  if (typeStr == "33") speed = Vinyl::ThirtyThree;
  else if (typeStr == "45") speed = Vinyl::FortyFive;

  return std::make_shared<Vinyl>(obj.firstChildElement("name").text().toStdString(),
                                 obj.firstChildElement("price").text().toDouble(),
                                 QDateTime::fromString(obj.firstChildElement("date").text(), Qt::ISODate),
                                 obj.firstChildElement("availableCopies").text().toInt(),
                                 obj.firstChildElement("image").text().toStdString(),
                                 obj.firstChildElement("artist").text().toStdString(),
                                 obj.firstChildElement("publisher").text().toStdString(),
                                 obj.firstChildElement("duration").text().toInt(),
                                 obj.firstChildElement("color").text().toStdString(),
                                 format,
                                 speed
                                );
}

std::shared_ptr<Movie> XmlImport::createMovie(const QDomElement &obj) {
  return std::make_shared<Movie>(obj.firstChildElement("name").text().toStdString(),
                               obj.firstChildElement("price").text().toDouble(),
                               QDateTime::fromString(obj.firstChildElement("date").text(), Qt::ISODate),
                               obj.firstChildElement("availableCopies").text().toInt(),
                               obj.firstChildElement("image").text().toStdString(),
                               obj.firstChildElement("director").text().toStdString(),
                               obj.firstChildElement("photo_director").text().toStdString(),
                               obj.firstChildElement("protagonist").text().toStdString(),
                               obj.firstChildElement("duration").text().toInt(),
                               obj.firstChildElement("wd").text().toStdString()
                              );
}

std::vector<std::shared_ptr<Product> > XmlImport::importFromFile(QString filename) {
  // Vector of products to return
  std::vector<std::shared_ptr<Product> > importedProducts;

  // Access to the file
  QFile file(filename);
  if (!file.open(QIODevice::ReadOnly)) {
    throw std::runtime_error("Cannot open file");
  }

  // Read the file content
  // const QByteArray data = file.readAll();
  // file.close();

  // Parse the XML content
  QDomDocument doc;
  if (!doc.setContent(&file)) {
    throw std::runtime_error("Invalid XML format");
  }

  // Get the root element
  QDomElement root = doc.documentElement();
  if (root.tagName() != "products") {
    throw std::runtime_error("Missing 'products' element in XML");
  }


  // Iterate through the products
  QDomElement product = root.firstChildElement();
  while (!product.isNull()) {
    QString type = product.tagName();
    std::shared_ptr<Product> prod = createFromXml(product, type);if (prod) {
      importedProducts.push_back(prod);
    }
    product = product.nextSiblingElement();
  }

  return importedProducts;
}
