#ifndef JSONMOVIEFACTORY_H
#define JSONMOVIEFACTORY_H

#include <memory>
#include "../JsonProductFactory.h"

class Product;
class QJsonObject;

class JsonMovieFactory : public JsonProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QJsonObject &element);
};

#endif
