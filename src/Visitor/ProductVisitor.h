#ifndef PRODUCTVISITOR_H
#define PRODUCTVISITOR_H

class Movie;
class Book;
class CD;
class Magazine;
class Comic;
class Vinyl;

class ProductVisitor {
public:
  virtual ~ProductVisitor() = default;
  virtual void visit(Book &book) = 0;
  virtual void visit(CD &cd) = 0;
  virtual void visit(Magazine &magazine) = 0;
  virtual void visit(Comic &comic) = 0;
  virtual void visit(Vinyl &vinyl) = 0;
  virtual void visit(Movie &film) = 0;
};

#endif // PRODUCTVISITOR_H
