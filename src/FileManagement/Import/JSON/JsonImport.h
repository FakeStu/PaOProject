#ifndef JSONIMPORTVISITOR_H
#define JSONIMPORTVISITOR_H

#include <memory>
#include <vector>
#include "..\Import.h"

class QString;
class QJsonObject;
class Movie;
class Vinyl;
class Comic;
class Magazine;
class CD;
class Book;
class Product;

class JsonImport : public Import {
private:
  std::shared_ptr<Book> createBook(const QJsonObject &obj);
  std::shared_ptr<Magazine> createMagazine(const QJsonObject &obj);
  std::shared_ptr<Comic> createComic(const QJsonObject &obj);
  std::shared_ptr<CD> createCD(const QJsonObject &obj);
  std::shared_ptr<Vinyl> createVinyl(const QJsonObject &obj);
  std::shared_ptr<Movie> createMovie(const QJsonObject &obj);

  std::shared_ptr<Product> createFromJson(const QJsonObject &obj, const QString &type);

public:
  JsonImport() = default;
  std::vector<std::shared_ptr<Product> > importFromFile(const QString &filename);
};
#endif
