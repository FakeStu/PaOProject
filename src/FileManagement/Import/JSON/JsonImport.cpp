#include "JsonImport.h"

#include <iostream>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "..\..\..\Model\Book.h"
#include "..\..\..\Model\CD.h"
#include "..\..\..\Model\Comic.h"
#include "..\..\..\Model\Magazine.h"
#include "..\..\..\Model\Movie.h"
#include "..\..\..\Model\Vinyl.h"

std::shared_ptr<Product> JsonImport::createFromJson(const QJsonObject &obj, const QString &type) {
  if (type == "book") return createBook(obj);
  if (type == "magazine") return createMagazine(obj);
  if (type == "comic") return createComic(obj);
  if (type == "cd") return createCD(obj);
  if (type == "vinyl") return createVinyl(obj);
  if (type == "movie") return createMovie(obj);

  return nullptr;
}

// TODO: Refactor to avoid code duplication -> use a common method for PaperProduct | Periodical | Disk
std::shared_ptr<Book> JsonImport::createBook(const QJsonObject &obj) {
  return std::make_shared<Book>(obj["name"].toString().toStdString(),
                                obj["price"].toDouble(),
                                QDateTime::fromString(obj["date"].toString(), Qt::ISODate),
                                obj["availableCopies"].toInt(),
                                obj["image"].toString().toStdString(),
                                obj["author"].toString().toStdString(),
                                obj["editor"].toString().toStdString(),
                                obj["genre"].toString().toStdString(),
                                obj["pages"].toInt(),
                                obj["binding"].toString().toStdString(),
                                obj["language"].toString().toStdString()
                               );
}

std::shared_ptr<Magazine> JsonImport::createMagazine(const QJsonObject &obj) {
  Periodical::periodicalType periodicity;
  QString perStr = obj["periodicity"].toString();
  if (perStr == "daily") periodicity = Periodical::daily;
  else if (perStr == "weekly") periodicity = Periodical::weekly;
  else if (perStr == "monthly") periodicity = Periodical::monthly;
  else periodicity = Periodical::annually;

  return std::make_shared<Magazine>(obj["name"].toString().toStdString(),
                                    obj["price"].toDouble(),
                                    QDateTime::fromString(obj["date"].
                                                          toString(),
                                                          Qt::ISODate),
                                    obj["availableCopies"].toInt(),
                                    obj["image"].toString().toStdString(),
                                    obj["author"].toString().toStdString(),
                                    obj["editor"].toString().toStdString(),
                                    obj["genre"].toString().toStdString(),
                                    obj["pages"].toInt(),
                                    periodicity,
                                    obj["topic"].toString().toStdString()
                                   );
}

std::shared_ptr<Comic> JsonImport::createComic(const QJsonObject &obj) {
  Periodical::periodicalType periodicity;
  QString perStr = obj["periodicity"].toString();
  if (perStr == "daily") periodicity = Periodical::daily;
  else if (perStr == "weekly") periodicity = Periodical::weekly;
  else if (perStr == "monthly") periodicity = Periodical::monthly;
  else periodicity = Periodical::annually;

  return std::make_shared<Comic>(obj["name"].toString().toStdString(),
                                 obj["price"].toDouble(),
                                 QDateTime::fromString(obj["date"].toString(), Qt::ISODate),
                                 obj["availableCopies"].toInt(),
                                 obj["image"].toString().toStdString(),
                                 obj["author"].toString().toStdString(),
                                 obj["editor"].toString().toStdString(),
                                 obj["genre"].toString().toStdString(),
                                 obj["pages"].toInt(),
                                 periodicity,
                                 obj["volume"].toInt(),
                                 obj["edition"].toString().toStdString()
                                );
}

std::shared_ptr<CD> JsonImport::createCD(const QJsonObject &obj) {
  CD::BookType bookType;
  QString typeStr = obj["bookType"].toString();
  if (typeStr == "Red") bookType = CD::Red;
  else if (typeStr == "Yellow") bookType = CD::Yellow;
  else if (typeStr == "Orange") bookType = CD::Orange;
  else if (typeStr == "Green") bookType = CD::Green;
  else if (typeStr == "White") bookType = CD::White;
  else bookType = CD::Blue;

  return std::make_shared<CD>(obj["name"].toString().toStdString(),
                              obj["price"].toDouble(),
                              QDateTime::fromString(obj["date"].toString(), Qt::ISODate),
                              obj["availableCopies"].toInt(),
                              obj["image"].toString().toStdString(),
                              obj["artist"].toString().toStdString(),
                              obj["publisher"].toString().toStdString(),
                              obj["duration"].toInt(),
                              obj["diameter"].toInt(),
                              bookType
                             );
}

std::shared_ptr<Vinyl> JsonImport::createVinyl(const QJsonObject &obj) {
  Vinyl::FormatType format;
  int formatInt = obj["format"].toString().toInt();
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
      format = Vinyl::FormatType::Twelve;
  }

  Vinyl::SpeedType speed = (obj["speed"].toString().toInt() == 33)
                             ? Vinyl::SpeedType::ThirtyThree
                             : Vinyl::SpeedType::FortyFive;

  return std::make_shared<Vinyl>(obj["name"].toString().toStdString(),
                                 obj["price"].toDouble(),
                                 QDateTime::fromString(obj["date"].toString(), Qt::ISODate),
                                 obj["availableCopies"].toInt(),
                                 obj["image"].toString().toStdString(),
                                 obj["artist"].toString().toStdString(),
                                 obj["publisher"].toString().toStdString(),
                                 obj["duration"].toInt(),
                                 obj["color"].toString().toStdString(),
                                 format,
                                 speed
                                );
}

std::shared_ptr<Movie> JsonImport::createMovie(const QJsonObject &obj) {
  return std::make_shared<Movie>(obj["name"].toString().toStdString(),
                                 obj["price"].toDouble(),
                                 QDateTime::fromString(obj["date"].toString(), Qt::ISODate),
                                 obj["availableCopies"].toInt(),
                                 obj["image"].toString().toStdString(),
                                 obj["director"].toString().toStdString(),
                                 obj["photoDirector"].toString().toStdString(),
                                 obj["protagonist"].toString().toStdString(),
                                 obj["duration"].toInt(),
                                 obj["genre"].toString().toStdString()
                                );
}

std::vector<std::shared_ptr<Product> > JsonImport::importFromFile(const QString &filename) {
  // Vector of products to return
  std::vector<std::shared_ptr<Product> > importedProducts;

  // Access to the file
  QFile file(filename);
  if (!file.open(QIODevice::ReadOnly)) {
    throw std::runtime_error("Cannot open file");
  }

  // Read the file content
  const QByteArray data = file.readAll();
  file.close();

  // Parse the JSON data
  const QJsonDocument doc = QJsonDocument::fromJson(data);
  if (!doc.isObject()) {
    throw std::runtime_error("Invalid JSON format");
  }

  // Get the root object
  QJsonObject root = doc.object();
  if (!root.contains("products")) {
    throw std::runtime_error("Missing 'products' object in JSON");
  }

  QJsonObject products = root["products"].toObject();

  // Iterate through the products
  for (const auto key : products.keys()) {
    for (const QJsonValue &jsonProduct : products[key].toArray()) {
      if (jsonProduct.isObject()) {
        auto obj = jsonProduct.toObject();
        std::shared_ptr<Product> product = createFromJson(obj, key);
        if (product) {
          importedProducts.push_back(product);
        }
      }
    }
  }

  return importedProducts;
}
