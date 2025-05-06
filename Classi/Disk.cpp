#include "Disk.h"

// Costruttore
Disk::Disk(string name, double price, QDateTime date, int totalCopies, string image, string artist, string publisher, int duration)
    : Product(name, price, date, totalCopies, image), artist(artist), publisher(publisher), duration(duration) {}


// Getter e Setter per artist
string Disk::getArtist() const {
    return artist;
}

void Disk::setArtist(const string& newArtist) {
    artist = newArtist;
}

// Getter e Setter per publisher
string Disk::getPublisher() const {
    return publisher;
}

void Disk::setPublisher(const string& newPublisher) {
    publisher = newPublisher;
}

// Getter e Setter per duration
int Disk::getDuration() const {
    return duration;
}

void Disk::setDuration(const int& newDuration) {
    duration = newDuration;
}
