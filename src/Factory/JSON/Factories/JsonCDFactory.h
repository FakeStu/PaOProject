#ifndef JSONCDFACTORY_H
#define JSONCDFACTORY_H

#include <memory>
#include "../JsonProductFactory.h"

class JsonCDFactory : public JsonProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QJsonObject &element);
};



#endif
