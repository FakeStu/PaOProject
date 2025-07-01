#include "XmlComicFactory.h"
#include <qdom.h>
#include "../../../Model/Comic.h"

std::shared_ptr<Product> XmlComicFactory::createProduct(const QDomElement &element) {
  return std::make_shared<Comic>(element.firstChildElement("name").text().toStdString(),
                                 element.firstChildElement("price").text().toDouble(),
                                 QDateTime::fromString(element.firstChildElement("date").text(), Qt::ISODate),
                                 element.firstChildElement("availableCopies").text().toInt(),
                                 element.firstChildElement("image").text().toStdString(),
                                 element.firstChildElement("author").text().toStdString(),
                                 element.firstChildElement("editor").text().toStdString(),
                                 element.firstChildElement("genre").text().toStdString(),
                                 element.firstChildElement("pages").text().toInt(),
                                 Periodical::periodicityFromString(element.firstChildElement("periodicity").text().toStdString()),
                                 element.firstChildElement("volume").text().toInt(),
                                 element.firstChildElement("edition").text().toStdString()
                                );
}
