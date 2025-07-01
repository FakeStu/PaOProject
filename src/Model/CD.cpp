#include "CD.h"
#include "../Visitor/ProductVisitor.h"


CD::CD(string name,
       double price,
       QDateTime date,
       int totalCopies,
       string image,
       string artist,
       string publisher,
       int duration,
       int diameter,
       BookType bookType) : Disk(name,
                                 price,
                                 date,
                                 totalCopies,
                                 image,
                                 artist,
                                 publisher,
                                 duration),
                            diameter(diameter),
                            bookType(bookType) {}

void CD::accept(ProductVisitor &visitor) { visitor.visit(*this); }

// Getter e Setter per diameter
int CD::getDiameter() const {
  return diameter;
}

void CD::setDiameter(const int &newDiameter) {
  diameter = newDiameter;
}

CD::BookType CD::getBookType() const {
  return bookType;
}

string CD::getBookTypeAsString() const {
  switch (bookType) {
    case Red:
      return "Red";
    case Yellow:
      return "Yellow";
    case Orange:
      return "Orange";
    case Green:
      return "Green";
    case White:
      return "White";
    case Blue:
      return "Blue";
    default:
      return "Unknown";
  }
}

void CD::setBookType(const BookType &type) {
  bookType = type;
}

void CD::setBookTypeFromString(const string &type) {
  if (type == "Red") bookType = Red;
  else if (type == "Yellow") bookType = Yellow;
  else if (type == "Orange") bookType = Orange;
  else if (type == "Green") bookType = Green;
  else if (type == "White") bookType = White;
  else if (type == "Blue") bookType = Blue;
  else throw std::invalid_argument("Invalid book type string");
}

