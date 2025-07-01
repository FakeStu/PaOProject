#ifndef EXPORTVISITOR_H
#define EXPORTVISITOR_H

#include "ProductVisitor.h"

class Product;

class ExportVisitor : public ProductVisitor {
public:
  virtual void exportToFile(const QString &filename, const std::vector<std::shared_ptr<Product> > &products) = 0;
};

#endif
