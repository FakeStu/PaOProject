#include "XmlMagazineFactory.h"
#include <qdom.h>
#include "../../../Model/Magazine.h"

class Product;

std::shared_ptr<Product> XmlMagazineFactory::createProduct(const QDomElement &element) {
  return std::make_shared<Magazine>(element.firstChildElement("name").text().toStdString(),
                                    element.firstChildElement("price").text().toDouble(),
                                    QDateTime::fromString(element.firstChildElement("date").text(), Qt::ISODate),
                                    element.firstChildElement("availableCopies").text().toInt(),
                                    element.firstChildElement("image").text().toStdString(),
                                    element.firstChildElement("author").text().toStdString(),
                                    element.firstChildElement("editor").text().toStdString(),
                                    element.firstChildElement("genre").text().toStdString(),
                                    element.firstChildElement("pages").text().toInt(),
                                    Periodical::periodicityFromString(element.firstChildElement("periodicity").text().toStdString()),
                                    element.firstChildElement("topic").text().toStdString()
                                   );
}
