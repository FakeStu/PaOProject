#ifndef JSONIMPORTVISITOR_H
#define JSONIMPORTVISITOR_H
#include <memory>
#include <vector>

class Movie;
class Vinyl;
class Comic;
class Magazine;
class CD;
class Book;
class QJsonObject;
class Product;

class JsonImportVisitor {
private:
  std::vector<std::shared_ptr<Product> > importedProducts;

  std::shared_ptr<Product> createFromJson(const QJsonObject &obj);
  std::shared_ptr<Book> createBook(const QJsonObject &obj);
  std::shared_ptr<CD> createCD(const QJsonObject &obj);
  std::shared_ptr<Magazine> createMagazine(const QJsonObject &obj);
  std::shared_ptr<Comic> createComic(const QJsonObject &obj);
  std::shared_ptr<Vinyl> createVinyl(const QJsonObject &obj);
  std::shared_ptr<Movie> createMovie(const QJsonObject &obj);

public:
  std::vector<std::shared_ptr<Product> > importFromFile(const std::string &filename);
};
#endif
