#ifndef XMLPRODUCTFACTORY_H
#define XMLPRODUCTFACTORY_H

#include <memory>
#include "../ProductFactory.h"

class QDomElement;
class Product;

class XmlProductFactory : public ProductFactory {
public:
  virtual ~XmlProductFactory() = default;
  virtual std::shared_ptr<Product> createProduct(const QDomElement &element) = 0;
  std::shared_ptr<Product> createProduct() {return nullptr;};
};

#endif
