#ifndef XMBOOKLFACTORY_H
#define XMBOOKLFACTORY_H

#include "../XmlProductFactory.h"

class Product;

class XmlBookFactory : public XmlProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QDomElement &element);
};

#endif
