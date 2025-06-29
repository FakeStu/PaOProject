#ifndef XMLIMPORT_H
#define XMLIMPORT_H

#include <memory>
#include <qdom.h>

#include "..\Import.h"

class QString;
class Movie;
class Vinyl;
class Comic;
class Magazine;
class CD;
class Book;
class Product;

class XmlImport : public Import {
private:
  std::shared_ptr<Book> createBook(const QDomElement &obj);
  std::shared_ptr<Magazine> createMagazine(const QDomElement &obj);
  std::shared_ptr<Comic> createComic(const QDomElement &obj);
  std::shared_ptr<CD> createCD(const QDomElement &obj);
  std::shared_ptr<Vinyl> createVinyl(const QDomElement &obj);
  std::shared_ptr<Movie> createMovie(const QDomElement &obj);

  std::shared_ptr<Product> createFromXml(const QDomElement &obj, const QString &type);

public:
  XmlImport() = default;
  std::vector<std::shared_ptr<Product> > importFromFile(QString filename);
};

#endif
