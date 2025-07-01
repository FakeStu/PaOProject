#ifndef XMLMAGAZINEFACTORY_H
#define XMLMAGAZINEFACTORY_H

#include "../XmlProductFactory.h"

class QDomElement;
class Product;

class XmlMagazineFactory : public XmlProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QDomElement &element);
};



#endif
