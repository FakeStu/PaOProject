#ifndef XMLCDFACTORY_H
#define XMLCDFACTORY_H

#include "../XmlProductFactory.h"

class Product;
class QDomElement;

class XmlCDFactory : public XmlProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QDomElement &element);
};



#endif
