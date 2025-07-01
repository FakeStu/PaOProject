#ifndef JSONBOOKFACTORY_H
#define JSONBOOKFACTORY_H

#include <memory>
#include "../JsonProductFactory.h"

class Product;
class QJsonObject;

class JsonBookFactory : public JsonProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QJsonObject &element);
};

#endif
