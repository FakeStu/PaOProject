#ifndef CD_H
#define CD_H
#include "Disk.h"

class ProductVisitor;

class CD : public Disk {
public:
  enum BookType { Red, Yellow, Orange, Green, White, Blue };
  static BookType bookTypeFromString(const string &type) {
    if (type == "Red")
      return BookType::Red;
    else if (type == "Yellow")
      return BookType::Yellow;
    else if (type == "Orange")
      return BookType::Orange;
    else if (type == "Green")
      return BookType::Green;
    else if (type == "White")
      return BookType::White;
    else if (type == "Blue")
      return BookType::Blue;
    else
      throw std::invalid_argument("Invalid book type");
  }

private:
  int diameter;
  BookType bookType;

public:
  CD(string name,
     double price,
     QDateTime date,
     int totalCopies,
     string image,
     string artist,
     string publisher,
     int duration,
     int diameter,
     BookType bookType);

  virtual ~CD() = default;
  virtual void accept(ProductVisitor &visitor);
  int getDiameter() const;
  void setDiameter(const int &newDiameter);
  BookType getBookType() const;
  string getBookTypeAsString() const;
  void setBookType(const BookType &type);
  void setBookTypeFromString(const string &type);
};

#endif
