#include "JsonBookFactory.h"
#include <QJsonObject>
#include "../../../Model/Book.h"

class QJsonelementect;
class Product;

std::shared_ptr<Product> JsonBookFactory::createProduct(const QJsonObject &element) {
  return std::make_shared<Book>(element["name"].toString().toStdString(),
                                element["price"].toDouble(),
                                QDateTime::fromString(element["date"].toString(), Qt::ISODate),
                                element["availableCopies"].toInt(),
                                element["image"].toString().toStdString(),
                                element["author"].toString().toStdString(),
                                element["editor"].toString().toStdString(),
                                element["genre"].toString().toStdString(),
                                element["pages"].toInt(),
                                element["binding"].toString().toStdString(),
                                element["language"].toString().toStdString()
                               );
}
