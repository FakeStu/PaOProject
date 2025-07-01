#ifndef JSONCOMICFACTORY_H
#define JSONCOMICFACTORY_H

#include <memory>
#include "../JsonProductFactory.h"

class JsonComicFactory : public JsonProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QJsonObject &element);
};



#endif
