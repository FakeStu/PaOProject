#include "Movie.h"


Movie::Movie(string name, double price, QDateTime date, int totalCopies,
             string image, string director, string photo_director,
             string protagonist, int duration,
             string genre) : Product(name, price, date, totalCopies, image),
                             director(director), photo_director(photo_director),
                             protagonist(protagonist), duration(duration),
                             genre(genre) {}

string Movie::getDirector() const {
  return director;
}

void Movie::setDirector(const string &newDirector) {
  director = newDirector;
}

string Movie::getPhotoDirector() const {
  return photo_director;
}

void Movie::setPhotoDirector(const string &newPhotoDirector) {
  photo_director = newPhotoDirector;
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
