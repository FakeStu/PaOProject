#include "JsonMagazineFactory.h"
#include <QJsonObject>
#include "../../../Model/Magazine.h"

std::shared_ptr<Product> JsonMagazineFactory::createProduct(const QJsonObject &element) {
  return std::make_shared<Magazine>(element["name"].toString().toStdString(),
                                    element["price"].toDouble(),
                                    QDateTime::fromString(element["date"].
                                                          toString(),
                                                          Qt::ISODate),
                                    element["availableCopies"].toInt(),
                                    element["image"].toString().toStdString(),
                                    element["author"].toString().toStdString(),
                                    element["editor"].toString().toStdString(),
                                    element["genre"].toString().toStdString(),
                                    element["pages"].toInt(),
                                    Periodical::periodicityFromString(element["periodicity"].toString().toStdString()),
                                    element["topic"].toString().toStdString()
                                   );
}
