#ifndef IMPORT_H
#define IMPORT_H

class Product;
class QString;

class Import {
public:
  virtual ~Import() = default;
  virtual std::vector<std::shared_ptr<Product> > importFromFile(const QString &filename) = 0;
};

#endif
