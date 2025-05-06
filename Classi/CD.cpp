#include "CD.h"


CD::CD(string name, double price, QDateTime date, int totalCopies, string image, string artist, string publisher, int duration, int diameter, BookType bookType)
    : Disk(name, price, date, totalCopies, image, artist, publisher, duration), diameter(diameter), bookType(bookType) {}

// Getter e Setter per diameter
int CD::getDiameter() const {
    return diameter;
}

void CD::setDiameter(const int& newDiameter) {
    diameter = newDiameter;
}


CD::BookType CD::getBookType() const {
    return bookType;
}

void CD::setBookType(const BookType& type) {
    bookType = type;
}

string CD::getBookTypeAsString() const {    //VERSIONE con 2 getter per l'enum, in base a cosa ci servirà in futuro decideremo quale usare.
    switch (bookType) {
    case Red:    return "Red";
    case Yellow: return "Yellow";
    case Orange: return "Orange";
    case Green:  return "Green";
    case White:  return "White";
    case Blue:   return "Blue";
    default:     return "Unknown";
    }
}
