#include "Book.h"
#include "../Visitor/ProductVisitor.h"

Book::Book(string name,
           double price,
           QDateTime date,
           int totalCopies,
           string image,
           string author,
           string editor,
           string genre,
           int pages,
           string binding,
           string original_language) : PaperProduct(name,
                                                    price,
                                                    date,
                                                    totalCopies,
                                                    image,
                                                    author,
                                                    editor,
                                                    genre,
                                                    pages),
                                       binding(binding),
                                       original_language(original_language) {}

void Book::accept(ProductVisitor &visitor) { visitor.visit(*this); }

string Book::getBinding() const { return binding; }

void Book::setBinding(const string &newBinding) { binding = newBinding; }

string Book::getLanguage() const { return original_language; }

void Book::setLanguage(const string &language) { original_language = language; }
