#include "XmlBookFactory.h"
#include <qdom.h>
#include "../../../Model/Book.h"

std::shared_ptr<Product> XmlBookFactory::createProduct(const QDomElement &element) {
  return std::make_shared<Book>(element.firstChildElement("name").text().toStdString(),
                                element.firstChildElement("price").text().toDouble(),
                                QDateTime::fromString(element.firstChildElement("date").text(), Qt::ISODate),
                                element.firstChildElement("availableCopies").text().toInt(),
                                element.firstChildElement("image").text().toStdString(),
                                element.firstChildElement("author").text().toStdString(),
                                element.firstChildElement("editor").text().toStdString(),
                                element.firstChildElement("genre").text().toStdString(),
                                element.firstChildElement("pages").text().toInt(),
                                element.firstChildElement("binding").text().toStdString(),
                                element.firstChildElement("language").text().toStdString()
                               );
}
