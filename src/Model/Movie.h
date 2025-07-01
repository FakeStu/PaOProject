#ifndef MOVIE_H
#define MOVIE_H
#include "Product.h"
#include <string>
using std::string;

class ProductVisitor;

class Movie : public Product {
private:
  string director;
  string photo_director;
  string protagonist;
  int duration;
  string genre;

public:
  Movie(string name,
        double price,
        QDateTime date,
        int totalCopies,
        string image,
        string director,
        string photoDirector,
        string protagonist,
        int duration,
        string genre);

  virtual ~Movie() = default;
  virtual void accept(ProductVisitor &visitor);
  string getDirector() const;
  string getPhotoDirector() const;
  string getProtagonist() const;
  int getDuration() const;
  string getGenre() const;
  void setDirector(const string &newDirector);
  void setPhotoDirector(const string &newPhoto_director);
  void setProtagonist(const string &newProtagonist);
  void setDuration(const int &newDuration);
  void setGenre(const string &newGenre);
};
#endif //MOVIE_H
