#ifndef BOOK_H
#define BOOK_H
#include "PaperProduct.h"

class ProductVisitor;

class Book : public PaperProduct {
private:
  string binding;
  string original_language;

public:
  Book(string name,
       double price,
       QDateTime date,
       int totalCopies,
       string image,
       string author,
       string editor,
       string genre,
       int pages,
       string binding,
       string original_language);
  virtual ~Book() = default;
  virtual void accept(ProductVisitor &visitor);
  string getBinding() const;
  string getLanguage() const;
  void setBinding(const string &newBinding);
  void setLanguage(const string &language);
};
#endif
