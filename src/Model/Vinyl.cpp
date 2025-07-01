#include "Vinyl.h"
#include "../Visitor/ProductVisitor.h"


Vinyl::Vinyl(string name,
             double price,
             QDateTime date,
             int totalCopies,
             string image,
             string artist,
             string publisher,
             int duration,
             string color,
             FormatType format,
             SpeedType speed) : Disk(name,
                                     price,
                                     date,
                                     totalCopies,
                                     image,
                                     artist,
                                     publisher,
                                     duration),
                                color(color),
                                format(format),
                                speed(speed) {}


void Vinyl::accept(ProductVisitor &visitor) { visitor.visit(*this); }

string Vinyl::getColor() const {
  return color;
}

void Vinyl::setColor(const string &color) {
  this->color = color;
}

Vinyl::FormatType Vinyl::getFormat() const {
  return format;
}

string Vinyl::getFormatAsString() const {
  switch (format) {
    case Twelve:
      return "Twelve";
    case Ten:
      return "Ten";
    case Seven:
      return "Seven";
    default:
      return "Unknown";
  }
}

void Vinyl::setFormat(const FormatType &format) {
  this->format = format;
}

void Vinyl::setFormatFromString(const string &format) {
  if (format == "12") this->format = Twelve;
  else if (format == "10") this->format = Ten;
  else if (format == "7") this->format = Seven;
  else throw std::invalid_argument("Invalid format string");
}

Vinyl::SpeedType Vinyl::getSpeed() const {
  return speed;
}

string Vinyl::getSpeedAsString() const {
  switch (speed) {
    case ThirtyThree:
      return "ThirtyThree";
    case FortyFive:
      return "FortyFive";
    default:
      return "Unknown";
  }
}

void Vinyl::setSpeed(const SpeedType &speed) {
  this->speed = speed;
}

void Vinyl::setSpeedFromString(const string &speed) {
  if (speed == "33") this->speed = ThirtyThree;
  else if (speed == "45") this->speed = FortyFive;
  else throw std::invalid_argument("Invalid speed string");
}

