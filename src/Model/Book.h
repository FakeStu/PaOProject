#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "Paper_Product.h"
using std::string;

class Book : public Paper_Product {
private:
  string binding;
  string original_language;

public:
  Book(string name, double price, QDateTime date, int totalCopies, string image,
       string author, string editor, string genre, int pages, string binding,
       string original_language);
  virtual ~Book() = default;
  string getBinding() const;
  string getLanguage() const;
  void setBinding(const string &newBinding);
  void setLanguage(const string &language);
};
#endif // BOOK_H
