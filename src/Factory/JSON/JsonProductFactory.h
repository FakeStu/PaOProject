#ifndef JSONPRODUCTFACTORY_H
#define JSONPRODUCTFACTORY_H

#include <memory>
#include "../ProductFactory.h"

class QJsonObject;
class Product;

class JsonProductFactory : public ProductFactory {
public:
  virtual ~JsonProductFactory() = default;
  virtual std::shared_ptr<Product> createProduct(const QJsonObject &element) = 0;
  std::shared_ptr<Product> createProduct() { return nullptr; };
};

#endif
