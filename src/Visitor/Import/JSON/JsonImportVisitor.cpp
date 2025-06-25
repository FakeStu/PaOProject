#include "JsonImportVisitor.h"
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

std::vector<std::shared_ptr<Product> > JsonImportVisitor::importFromFile(const std::string &filename) {
  QFile file(QString::fromStdString(filename));
  if (!file.open(QIODevice::ReadOnly)) {
    throw std::runtime_error("Cannot open file");
  }

  QByteArray data = file.readAll();
  QJsonDocument doc = QJsonDocument::fromJson(data);

  if (!doc.isObject()) {
    throw std::runtime_error("Invalid JSON format");
  }

  QJsonObject root = doc.object();
  QJsonArray array = root["products"].toArray();

  importedProducts.clear();

  for (const auto &value: array) {
    if (value.isObject()) {
      if (auto product = createFromJson(value.toObject())) {
        importedProducts.push_back(product);
      }
    }
  }

  return importedProducts;
}

std::shared_ptr<Product> JsonImportVisitor::createFromJson(const QJsonObject &obj) {
  QString type = obj["type"].toString();

  if (type == "Book") return createBook(obj);
  if (type == "CD") return createCD(obj);
  if (type == "Magazine") return createMagazine(obj);
  if (type == "Comic") return createComic(obj);
  if (type == "Vinyl") return createVinyl(obj);
  if (type == "Movie") return createMovie(obj);

  return nullptr;
}

std::shared_ptr<Book> JsonImportVisitor::createBook(const QJsonObject &obj) {
  return std::make_shared<Book>(obj["name"].toString().toStdString(),
                                obj["price"].toDouble(),
                                QDateTime::fromString(obj["date"].toString(), Qt::ISODate),
                                obj["totalCopies"].toInt(),
                                obj["image"].toString().toStdString(),
                                obj["author"].toString().toStdString(),
                                obj["editor"].toString().toStdString(),
                                obj["genre"].toString().toStdString(),
                                obj["pages"].toInt(),
                                obj["binding"].toString().toStdString(),
                                obj["language"].toString().toStdString()
                               );
}

std::shared_ptr<CD> JsonImportVisitor::createCD(const QJsonObject &obj) {
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
                              obj["totalCopies"].toInt(),
                              obj["image"].toString().toStdString(),
                              obj["artist"].toString().toStdString(),
                              obj["publisher"].toString().toStdString(),
                              obj["duration"].toInt(),
                              obj["diameter"].toInt(),
                              bookType
                             );
}

std::shared_ptr<Magazine> JsonImportVisitor::createMagazine(const QJsonObject &obj) {
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
                                    obj["totalCopies"].toInt(),
                                    obj["image"].toString().toStdString(),
                                    obj["author"].toString().toStdString(),
                                    obj["editor"].toString().toStdString(),
                                    obj["genre"].toString().toStdString(),
                                    obj["pages"].toInt(),
                                    periodicity,
                                    obj["topic"].toString().toStdString()
                                   );
}

std::shared_ptr<Comic> JsonImportVisitor::createComic(const QJsonObject &obj) {
  Periodical::periodicalType periodicity;
  QString perStr = obj["periodicity"].toString();
  if (perStr == "daily") periodicity = Periodical::daily;
  else if (perStr == "weekly") periodicity = Periodical::weekly;
  else if (perStr == "monthly") periodicity = Periodical::monthly;
  else periodicity = Periodical::annually;

  return std::make_shared<Comic>(obj["name"].toString().toStdString(),
                                 obj["price"].toDouble(),
                                 QDateTime::fromString(obj["date"].toString(), Qt::ISODate),
                                 obj["totalCopies"].toInt(),
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

std::shared_ptr<Vinyl> JsonImportVisitor::createVinyl(const QJsonObject &obj) {
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
                                 obj["totalCopies"].toInt(),
                                 obj["image"].toString().toStdString(),
                                 obj["artist"].toString().toStdString(),
                                 obj["publisher"].toString().toStdString(),
                                 obj["duration"].toInt(),
                                 obj["color"].toString().toStdString(),
                                 format,
                                 speed
                                );
}

std::shared_ptr<Movie> JsonImportVisitor::createMovie(const QJsonObject &obj) {
  return std::make_shared<Movie>(obj["name"].toString().toStdString(),
                                 obj["price"].toDouble(),
                                 QDateTime::fromString(obj["date"].toString(), Qt::ISODate),
                                 obj["totalCopies"].toInt(),
                                 obj["image"].toString().toStdString(),
                                 obj["director"].toString().toStdString(),
                                 obj["photoDirector"].toString().toStdString(),
                                 obj["protagonist"].toString().toStdString(),
                                 obj["duration"].toInt(),
                                 obj["genre"].toString().toStdString()
                                );
}
