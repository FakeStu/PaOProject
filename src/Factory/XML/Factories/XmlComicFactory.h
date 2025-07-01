#ifndef XMLCOMICFACTORY_H
#define XMLCOMICFACTORY_H

#include "../XmlProductFactory.h"

class Product;

class XmlComicFactory : public XmlProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QDomElement &element);
};



#endif
