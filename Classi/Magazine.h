
#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "Periodical.h"
#include <string>
#include "Periodical.h"
#include <string>
using std::string;

class Magazine : public Periodical {
private:
    string topic;
public:
    Magazine(string name, double price, QDateTime date, int totalCopies, string image, string author, string editor, string genre, int pages, periodicalType periodicity, string topic);
    virtual ~Magazine() = default;
    string getTopic() const;
    void setTopic(const string& newTopic);
};
#endif //MAGAZINE_H
