#include "XmlCDFactory.h"
#include <qdom.h>
#include "../../../Model/CD.h"

std::shared_ptr<Product> XmlCDFactory::createProduct(const QDomElement &element) {
  return std::make_shared<CD>(element.firstChildElement("name").text().toStdString(),
                              element.firstChildElement("price").text().toDouble(),
                              QDateTime::fromString(element.firstChildElement("date").text(), Qt::ISODate),
                              element.firstChildElement("availableCopies").text().toInt(),
                              element.firstChildElement("image").text().toStdString(),
                              element.firstChildElement("artist").text().toStdString(),
                              element.firstChildElement("publisher").text().toStdString(),
                              element.firstChildElement("duration").text().toInt(),
                              element.firstChildElement("diameter").text().toInt(),
                              CD::bookTypeFromString(element.firstChildElement("bookType").text().toStdString())
                             );
}