
#ifndef COMIC_H
#define COMIC_H
#include "Periodical.h"
#include <string>
using std::string;

class Comic : public Periodical {
private:
    int volume;
    string edition;

public:
    Comic(string name, double price, QDateTime date, int totalCopies, string image,
          string author, string editor, string genre, int pages,
          periodicalType periodicity, int volume, string edition);

    virtual ~Comic();

    int getVolume() const;
    string getEdition() const;
    void setVolume(const int& newVolume);
    void setEdition(const string& newEdition);
};
#endif //COMIC_H
