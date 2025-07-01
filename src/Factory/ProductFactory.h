#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include <memory>

class Product;

class ProductFactory {
public:
  virtual ~ProductFactory() = default;
  virtual std::shared_ptr<Product> createProduct() = 0;
};



#endif
