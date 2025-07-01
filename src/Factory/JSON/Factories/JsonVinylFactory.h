#ifndef JSONVINYLFACTORY_H
#define JSONVINYLFACTORY_H

#include <memory>
#include "../JsonProductFactory.h"

class Product;
class QJsonObject;

class JsonVinylFactory : public JsonProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QJsonObject &element);
};

#endif
