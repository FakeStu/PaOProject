#ifndef PERIODICAL_H
#define PERIODICAL_H

#include <QDateTime>
#include <string>
#include "PaperProduct.h"

using std::string;

class Periodical : public PaperProduct {
public:
  enum periodicalType { daily, weekly, monthly, annually };

private:
  periodicalType periodicity;

  // TODO: change Editor for Publisher
public:
  Periodical(string name,
             double price,
             QDateTime date,
             int totalCopies,
             string image,
             string author,
             string editor,
             string genre,
             int pages,
             periodicalType periodicity);

  virtual ~Periodical() = default;

  periodicalType getPeriodicity() const;
  string getPeriodicityAsString() const;
  void setPeriodicity(const periodicalType &type);
};

#endif //PERIODICAL_H
