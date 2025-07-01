#include "JsonComicFactory.h"
#include <QJsonObject>
#include "../../../Model/Comic.h"

class QJsonelementect;
class Product;

std::shared_ptr<Product> JsonComicFactory::createProduct(const QJsonObject &element) {
  return std::make_shared<Comic>(element["name"].toString().toStdString(),
                                 element["price"].toDouble(),
                                 QDateTime::fromString(element["date"].toString(), Qt::ISODate),
                                 element["availableCopies"].toInt(),
                                 element["image"].toString().toStdString(),
                                 element["author"].toString().toStdString(),
                                 element["editor"].toString().toStdString(),
                                 element["genre"].toString().toStdString(),
                                 element["pages"].toInt(),
                                 Periodical::periodicityFromString(element["periodicity"].toString().toStdString()),
                                 element["volume"].toInt(),
                                 element["edition"].toString().toStdString()
                                );
}