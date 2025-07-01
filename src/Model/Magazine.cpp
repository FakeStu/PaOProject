#include "Magazine.h"
#include "../Visitor/ProductVisitor.h"

Magazine::Magazine(string name,
                   double price,
                   QDateTime date,
                   int totalCopies,
                   string image,
                   string author,
                   string editor,
                   string genre,
                   int pages,
                   periodicalType periodicity,
                   string topic) : Periodical(name,
                                              price,
                                              date,
                                              totalCopies,
                                              image,
                                              author,
                                              editor,
                                              genre,
                                              pages,
                                              periodicity),
                                   topic(topic) {}

string Magazine::getTopic() const {
  return topic;
}

void Magazine::setTopic(const string &newTopic) {
  topic = newTopic;
}

void Magazine::accept(ProductVisitor &visitor) { visitor.visit(*this); }
