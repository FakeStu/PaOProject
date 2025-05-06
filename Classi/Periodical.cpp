#include "Periodical.h"

// Costruttore
Periodical::Periodical(string name, double price, QDateTime date, int totalCopies, string image, string author, string editor, string genre, int pages, periodicalType periodicity)
    : Paper_Product(name, price, date, totalCopies, image, author, editor, genre, pages), periodicity(periodicity) {}

string Periodical::getPeriodicity() const { // this is a get AS a String, o questa versione oppure quella usata per enum di CD ----> DA DECIDERE
    switch (periodicity) {
    case daily:   return "daily";
    case weekly:  return "weekly";
    case monthly: return "monthly";
    case annualy: return "annualy";
    default:      return "unknown";
    }
}

void Periodical::setPeriodicity(const periodicalType& type) {
    periodicity = type;
}
