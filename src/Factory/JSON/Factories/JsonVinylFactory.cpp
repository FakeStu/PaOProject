#include "JsonVinylFactory.h"
#include <QJsonObject>
#include "../../../Model/Vinyl.h"

class QJsonelementect;
class Product;

std::shared_ptr<Product> JsonVinylFactory::createProduct(const QJsonObject &element) {
  return std::make_shared<Vinyl>(element["name"].toString().toStdString(),
                                 element["price"].toDouble(),
                                 QDateTime::fromString(element["date"].toString(), Qt::ISODate),
                                 element["availableCopies"].toInt(),
                                 element["image"].toString().toStdString(),
                                 element["artist"].toString().toStdString(),
                                 element["publisher"].toString().toStdString(),
                                 element["duration"].toInt(),
                                 element["color"].toString().toStdString(),
                                 Vinyl::formatFromString(element["format"].toString().toStdString()),
                                 Vinyl::speedFromString(element["speed"].toString().toStdString())
                                );
}