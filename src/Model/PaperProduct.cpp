#include "PaperProduct.h"

PaperProduct::PaperProduct(string name,
                           double price,
                           QDateTime date,
                           int totalCopies,
                           string image,
                           string author,
                           string editor,
                           string genre,
                           int pages) : Product(name,
                                                price,
                                                date,
                                                totalCopies,
                                                image),
                                        author(author),
                                        editor(editor),
                                        genre(genre),
                                        pages(pages) {}

string PaperProduct::getAuthor() const {
  return author;
}

string PaperProduct::getEditor() const {
  return editor;
}

string PaperProduct::getGenre() const {
  return genre;
}

int PaperProduct::getPages() const {
  return pages;
}

void PaperProduct::setAuthor(const string &newAuthor) {
  author = newAuthor;
}

void PaperProduct::setEditor(const string &newEditor) {
  editor = newEditor;
}

void PaperProduct::setGenre(const string &newGenre) {
  genre = newGenre;
}

void PaperProduct::setPages(const int &newPages) {
  pages = newPages;
}
