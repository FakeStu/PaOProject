#include "JsonCDFactory.h"
#include <QJsonObject>
#include "../../../Model/CD.h"

class QJsonelementect;
class Product;

std::shared_ptr<Product> JsonCDFactory::createProduct(const QJsonObject &element) {
  return std::make_shared<CD>(element["name"].toString().toStdString(),
                              element["price"].toDouble(),
                              QDateTime::fromString(element["date"].toString(), Qt::ISODate),
                              element["availableCopies"].toInt(),
                              element["image"].toString().toStdString(),
                              element["artist"].toString().toStdString(),
                              element["publisher"].toString().toStdString(),
                              element["duration"].toInt(),
                              element["diameter"].toInt(),
                              CD::bookTypeFromString(element["bookType"].toString().toStdString())
                             );
}