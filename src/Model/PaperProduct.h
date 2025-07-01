#ifndef PAPER_PRODUCT_H
#define PAPER_PRODUCT_H

#include <string>
#include "Product.h"

using std::string;

class PaperProduct : public Product {
private:
  string author;
  string editor;
  string genre;
  int pages;

public:
  PaperProduct(string name,
                double price,
                QDateTime date,
                int totalCopies,
                string image,
                string author,
                string publisher,
                string genre,
                int pages);
  virtual ~PaperProduct() = default;
  string getAuthor() const;
  string getPublisher() const;
  string getGenre() const;
  int getPages() const;
  void setAuthor(const string &newAuthor);
  void setPublisher(const string &newEditor);
  void setGenre(const string &newGenre);
  void setPages(const int &newPages);
};
#endif //PAPER_PRODUCT_H
