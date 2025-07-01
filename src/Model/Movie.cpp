#include "Movie.h"
#include "../Visitor/ProductVisitor.h"


Movie::Movie(string name,
             double price,
             QDateTime date,
             int totalCopies,
             string image,
             string director,
             string photoDirector,
             string protagonist,
             int duration,
             string genre) : Product(name, price, date, totalCopies, image),
                             director(director),
                             photo_director(photoDirector),
                             protagonist(protagonist),
                             duration(duration),
                             genre(genre) {}


void Movie::accept(ProductVisitor &visitor) { visitor.visit(*this); }

string Movie::getDirector() const {
  return director;
}

void Movie::setDirector(const string &newDirector) {
  director = newDirector;
}

string Movie::getPhotoDirector() const {
  return photo_director;
}

void Movie::setPhotoDirector(const string &photoDirector) {
  this->photo_director = photoDirector;
}

string Movie::getProtagonist() const {
  return protagonist;
}

void Movie::setProtagonist(const string &newProtagonist) {
  protagonist = newProtagonist;
}

int Movie::getDuration() const {
  return duration;
}

void Movie::setDuration(const int &newDuration) {
  duration = newDuration;
}

string Movie::getGenre() const {
  return genre;
}

void Movie::setGenre(const string &newGenre) {
  genre = newGenre;
}
