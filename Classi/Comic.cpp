#include "Comic.h"

Comic::Comic(string name, double price, QDateTime date, int totalCopies, string image, string author, string editor, string genre, int pages, periodicalType periodicity, int volume, string edition)
    : Periodical(name, price, date, totalCopies, image, author, editor, genre, pages, periodicity), volume(volume), edition(edition) {}

Comic::~Comic() = default;

int Comic::getVolume() const {
    return volume;
}

void Comic::setVolume(const int& newVolume) {
    volume = newVolume;
}

string Comic::getEdition() const {
    return edition;
}

void Comic::setEdition(const string& newEdition) {
    edition = newEdition;
}