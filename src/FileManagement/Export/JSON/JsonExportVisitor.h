#ifndef JSONEXPORTVISITOR_H
#define JSONEXPORTVISITOR_H

#include <QJsonObject>
#include "../../../Visitor/ExportVisitor.h"

class Periodical;
class Disk;
class PaperProduct;
class Product;

class JsonExportVisitor : public ExportVisitor {
private:
  QJsonObject products;

public:
  JsonExportVisitor() = default;
  ~JsonExportVisitor() = default;

  void addCommonElements(const Product &product, QJsonObject &element);
  void addPaperProductElements(const PaperProduct &paperProduct, QJsonObject &element);
  void addPeriodicalProductElements(const Periodical &periodical, QJsonObject &element);
  void addDiskElements(const Disk &disk, QJsonObject &element);

  void visit(Book &book);
  void visit(Magazine &magazine);
  void visit(Comic &comic);
  void visit(CD &cd);
  void visit(Vinyl &vinyl);
  void visit(Movie &movie);

  void exportToFile(const QString &filename, const std::vector<std::shared_ptr<Product> > &products);
};

#endif
