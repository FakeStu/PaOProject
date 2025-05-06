
#ifndef DISK_H
#define DISK_H
#include "Product.h"
#include <string>
using std::string;

class Disk : public Product {
private:
    string artist;
    string publisher;
    int duration;
public:
    Disk(string name, double price, QDateTime date, int totalCopies, string image, string artist, string publisher, int duration);
    virtual ~Disk() = default;
    string getArtist() const;
    string getPublisher() const;
    int getDuration() const;
    void setArtist(const string& newArtist);
    void setPublisher(const string& newPublisher);
    void setDuration(const int& duration);
};

#endif //DISK_H
