#include "Periodical.h"

// Costruttore
Periodical::Periodical(string name,
                       double price,
                       QDateTime date,
                       int totalCopies,
                       string image,
                       string author,
                       string publisher,
                       string genre,
                       int pages,
                       periodicalType periodicity) : PaperProduct(name,
                                                                  price,
                                                                  date,
                                                                  totalCopies,
                                                                  image,
                                                                  author,
                                                                  publisher,
                                                                  genre,
                                                                  pages),
                                                     periodicity(periodicity) {}

Periodical::periodicalType Periodical::getPeriodicity() const {
  return periodicity;
}

string Periodical::getPeriodicityAsString() const {
  switch (periodicity) {
    case daily:
      return "daily";
    case weekly:
      return "weekly";
    case monthly:
      return "monthly";
    case annually:
      return "annually";
    default:
      return "unknown";
  }
}

void Periodical::setPeriodicity(const periodicalType &type) {
  periodicity = type;
}

void Periodical::setPeriodicityFromString(const string &type) {
  if (type == "daily") periodicity = daily;
  else if (type == "weekly") periodicity = weekly;
  else if (type == "monthly") periodicity = monthly;
  else if (type == "annually") periodicity = annually;
  else throw std::invalid_argument("Invalid book type string");
}
