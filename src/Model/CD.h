#ifndef CD_H
#define CD_H
#include "Disk.h"
#include <string>
using std::string;

class CD : public Disk {
public:
  enum BookType { Red, Yellow, Orange, Green, White, Blue };

private:
  int diameter;
  BookType bookType;

public:
  CD(string name, double price, QDateTime date, int totalCopies, string image,
     string artist, string publisher, int duration, int diameter,
     BookType bookType);

  virtual ~CD() = default;

  int getDiameter() const;
  BookType getBookType() const;
  void setDiameter(const int &newDiameter);
  void setBookType(const BookType &type);

  string getBookTypeAsString() const;
};

#endif //CD_H
