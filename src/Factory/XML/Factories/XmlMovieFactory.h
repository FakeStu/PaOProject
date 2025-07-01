#ifndef XMLMOVIEFACTORY_H
#define XMLMOVIEFACTORY_H

#include "../XmlProductFactory.h"

class XmlMovieFactory : public XmlProductFactory {
public:
  std::shared_ptr<Product> createProduct(const QDomElement &element);
};



#endif
