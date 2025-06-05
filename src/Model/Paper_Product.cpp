#include "Paper_Product.h"

Paper_Product::Paper_Product(string name, double price, QDateTime date,
                             int totalCopies, string image, string author,
                             string editor, string genre,
                             int pages) : Product(name, price, date,
                                                  totalCopies, image),
                                          author(author), editor(editor),
                                          genre(genre), pages(pages) {}

string Paper_Product::getAuthor() const {
  return author;
}

string Paper_Product::getEditor() const {
  return editor;
}

string Paper_Product::getGenre() const {
  return genre;
}

int Paper_Product::getPages() const {
  return pages;
}

void Paper_Product::setAuthor(const string &newAuthor) {
  author = newAuthor;
}

void Paper_Product::setEditor(const string &newEditor) {
  editor = newEditor;
}

void Paper_Product::setGenre(const string &newGenre) {
  genre = newGenre;
}

void Paper_Product::setPages(const int &newPages) {
  pages = newPages;
}
