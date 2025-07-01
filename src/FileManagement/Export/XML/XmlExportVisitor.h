#ifndef XMLEXPORTVISITOR_H
#define XMLEXPORTVISITOR_H

#include <QtXml/QDomDocument>
#include "../../../Visitor/ExportVisitor.h"

class Periodical;
class Disk;
class PaperProduct;
class Product;

class XmlExportVisitor : public ExportVisitor {
private:
  QDomDocument _doc;
  QDomElement _root;

public:
  XmlExportVisitor();
  ~XmlExportVisitor() = default;

  void addCommonElements(const Product &product, QDomElement &element);
  void addPaperProductElements(const PaperProduct &paperProduct, QDomElement &element);
  void addPeriodicalProductElements(const Periodical &periodical, QDomElement &element);
  void addDiskElements(const Disk &disk, QDomElement &element);

  void visit(Book &book);
  void visit(CD &cd);
  void visit(Magazine &magazine);
  void visit(Comic &comic);
  void visit(Vinyl &vinyl);
  void visit(Movie &movie);

  void exportToFile(const QString &filename, const std::vector<std::shared_ptr<Product> > &products);
};

#endif
