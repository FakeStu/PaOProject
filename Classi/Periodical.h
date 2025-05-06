
#ifndef PERIODICAL_H
#define PERIODICAL_H
#include "Paper_Product.h"
#include <string>
using std::string;

class Periodical : public Paper_Product {
public:
    enum periodicalType { daily, weekly, monthly, annualy };

private:
    periodicalType periodicity;

public:
    Periodical(string name, double price, QDateTime date, int totalCopies, string image, string author, string editor, string genre, int pages, periodicalType periodicity);

    virtual ~Periodical() = default;

    string getPeriodicity() const;
    void setPeriodicity(const periodicalType& type);
};

#endif //PERIODICAL_H
