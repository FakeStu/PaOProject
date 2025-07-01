#include "XmlVinylFactory.h"
#include <qdom.h>
#include "../../../Model/Vinyl.h"

std::shared_ptr<Product> XmlVinylFactory::createProduct(const QDomElement &element) {
  return std::make_shared<Vinyl>(element.firstChildElement("name").text().toStdString(),
                                 element.firstChildElement("price").text().toDouble(),
                                 QDateTime::fromString(element.firstChildElement("date").text(), Qt::ISODate),
                                 element.firstChildElement("availableCopies").text().toInt(),
                                 element.firstChildElement("image").text().toStdString(),
                                 element.firstChildElement("artist").text().toStdString(),
                                 element.firstChildElement("publisher").text().toStdString(),
                                 element.firstChildElement("duration").text().toInt(),
                                 element.firstChildElement("color").text().toStdString(),
                                 Vinyl::formatFromString(element.firstChildElement("format").text().toStdString()),
                                 Vinyl::speedFromString(element.firstChildElement("speed").text().toStdString())
                                );
}