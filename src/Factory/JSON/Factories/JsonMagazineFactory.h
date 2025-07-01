#ifndef JSONMAGAZINEFACTORY_H
#define JSONMAGAZINEFACTORY_H

#include <memory>
#include "../JsonProductFactory.h"

class JsonMagazineFactory : public JsonProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QJsonObject &element);
};



#endif
