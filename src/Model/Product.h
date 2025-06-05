#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <QDateTime>
using std::string;

class Product {
private:
  string name;
  double price;
  QDateTime date;
  int totalCopies;
  string image;

public:
  Product(string name, double price, QDateTime date, int totalCopies,
          string image);
  virtual ~Product() = default;
  string getName() const;
  double getPrice() const;
  QDateTime getDate() const;
  int getTotalCopies() const;
  QDateTime getImageDate() const;
  string getImage() const;
  void setName(const string &newName);
  void setPrice(const double &newPrice);
  void setDate(const QDateTime &newDate);
  void setTotalCopies(const int &newTotalCopies);
  void setImage(const string &newImage);
};

#endif //PRODUCT_H
