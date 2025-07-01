#include "JsonMovieFactory.h"
#include <QJsonObject>
#include "../../../Model/Movie.h"

class QJsonelementect;
class Product;

std::shared_ptr<Product> JsonMovieFactory::createProduct(const QJsonObject &element) {
  return std::make_shared<Movie>(element["name"].toString().toStdString(),
                                 element["price"].toDouble(),
                                 QDateTime::fromString(element["date"].toString(), Qt::ISODate),
                                 element["availableCopies"].toInt(),
                                 element["image"].toString().toStdString(),
                                 element["director"].toString().toStdString(),
                                 element["photoDirector"].toString().toStdString(),
                                 element["protagonist"].toString().toStdString(),
                                 element["duration"].toInt(),
                                 element["genre"].toString().toStdString()
                                );
}