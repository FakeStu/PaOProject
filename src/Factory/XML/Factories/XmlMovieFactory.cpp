#include "XmlMovieFactory.h"
#include <qdom.h>
#include "../../../Model/Movie.h"

std::shared_ptr<Product> XmlMovieFactory::createProduct(const QDomElement &element) {
  return std::make_shared<Movie>(element.firstChildElement("name").text().toStdString(),
                               element.firstChildElement("price").text().toDouble(),
                               QDateTime::fromString(element.firstChildElement("date").text(), Qt::ISODate),
                               element.firstChildElement("availableCopies").text().toInt(),
                               element.firstChildElement("image").text().toStdString(),
                               element.firstChildElement("director").text().toStdString(),
                               element.firstChildElement("photo_director").text().toStdString(),
                               element.firstChildElement("protagonist").text().toStdString(),
                               element.firstChildElement("duration").text().toInt(),
                               element.firstChildElement("wd").text().toStdString()
                              );
}