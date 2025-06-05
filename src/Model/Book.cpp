#include "Book.h"

Book::Book(string name, double price, QDateTime date, int totalCopies,
           string image, string author, string editor, string genre, int pages,
           string binding, string original_language) : Paper_Product(name,
    price, date, totalCopies, image, author, editor, genre,
    pages),
  binding(binding), original_language(original_language) {}

string Book::getBinding() const { return binding; }

void Book::setBinding(const string &newBinding) { binding = newBinding; }

string Book::getLanguage() const { return original_language; }

void Book::setLanguage(const string &language) { original_language = language; }

QJsonObject Book::toJson() const {
  QJsonObject obj;
  obj["name"] = QString::fromStdString(getName());
  obj["price"] = getPrice();
  obj["date"] = getDate().toString(Qt::ISODate);
  obj["totalCopies"] = getTotalCopies();
  obj["image"] = QString::fromStdString(getImage());
  obj["author"] = QString::fromStdString(getAuthor());
  obj["editor"] = QString::fromStdString(getEditor());
  obj["genre"] = QString::fromStdString(getGenre());
  obj["pages"] = getPages();
  obj["binding"] = QString::fromStdString(getBinding());
  obj["original_language"] = QString::fromStdString(getLanguage());
  return obj;
}

void Book::toXml(QXmlStreamWriter &writer) const {
  writer.writeStartElement("Book");
  writer.writeTextElement("name", QString::fromStdString(getName()));
  writer.writeTextElement("price", QString::number(getPrice()));
  writer.writeTextElement("date", getDate().toString(Qt::ISODate));
  writer.writeTextElement("totalCopies", QString::number(getTotalCopies()));
  writer.writeTextElement("image", QString::fromStdString(getImage()));
  writer.writeTextElement("author", QString::fromStdString(getAuthor()));
  writer.writeTextElement("editor", QString::fromStdString(getEditor()));
  writer.writeTextElement("genre", QString::fromStdString(getGenre()));
  writer.writeTextElement("pages", QString::number(getPages()));
  writer.writeTextElement("binding", QString::fromStdString(getBinding()));
  writer.writeTextElement("original_language", QString::fromStdString(getLanguage()));
}