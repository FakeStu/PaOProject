#ifndef JSONEXPORTVISITOR_H
#define JSONEXPORTVISITOR_H

#include <QJsonArray>
#include "..\..\ProductVisitor.h"

class JsonExportVisitor : public ProductVisitor {
private:
  QJsonArray products;

public:
  JsonExportVisitor() = default;
  ~JsonExportVisitor() = default;

  void visit(Book &book) override;
  void visit(CD &cd) override;
  void visit(Magazine &magazine) override;
  void visit(Comic &comic) override;
  void visit(Vinyl &vinyl) override;
  void visit(Movie &movie) override;

  void exportToFile(const std::string &filename);
};

#endif
