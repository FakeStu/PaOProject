#include "Product.h"

Product::Product(string name,
                 double price,
                 QDateTime date,
                 int totalCopies,
                 string image) : name(name),
                                 price(price),
                                 date(date),
                                 totalCopies(totalCopies),
                                 image(image) {}

string Product::getName() const {
  return name;
}

void Product::setName(const string &newName) {
  name = newName;
}

double Product::getPrice() const {
  return price;
}

void Product::setPrice(const double &newPrice) {
  price = newPrice;
}

QDateTime Product::getDate() const {
  return date;
}

void Product::setDate(const QDateTime &newDate) {
  date = newDate;
}

int Product::getTotalCopies() const {
  return totalCopies;
}

void Product::setTotalCopies(const int &newTotalCopies) {
  totalCopies = newTotalCopies;
}

string Product::getImage() const {
  return image;
}

void Product::setImage(const string &newImage) {
  image = newImage;
}
