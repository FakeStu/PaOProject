#ifndef PERIODICAL_H
#define PERIODICAL_H

#include <string>
#include "PaperProduct.h"

using std::string;

class Periodical : public PaperProduct {
public:
  enum periodicalType { daily, weekly, monthly, annually };

  static periodicalType periodicityFromString(const string &periodicity) {
    if (periodicity == "daily")
      return periodicalType::daily;
    else if (periodicity == "weekly")
      return periodicalType::weekly;
    else if (periodicity == "monthly")
      return periodicalType::monthly;
    else if (periodicity == "annually")
      return periodicalType::annually;
    else
      throw std::invalid_argument("Invalid periodicity type");
  }

private:
  periodicalType periodicity;

public:
  Periodical(string name,
             double price,
             QDateTime date,
             int totalCopies,
             string image,
             string author,
             string publisher,
             string genre,
             int pages,
             periodicalType periodicity);

  virtual ~Periodical() = default;

  periodicalType getPeriodicity() const;
  string getPeriodicityAsString() const;
  void setPeriodicity(const periodicalType &type);
  void setPeriodicityFromString(const string &type);
};

#endif //PERIODICAL_H
