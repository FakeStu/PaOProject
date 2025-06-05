#include "Vinyl.h"


Vinyl::Vinyl(string name, double price, QDateTime date, int totalCopies,
             string image, string artist, string publisher, int duration,
             string color, FormatType format,
             SpeedType speed) : Disk(name, price, date, totalCopies, image,
                                     artist, publisher, duration), color(color),
                                format(format), speed(speed) {}


string Vinyl::getColor() const {
  return color;
}

void Vinyl::setColor(const string &newColor) {
  color = newColor;
}

Vinyl::FormatType Vinyl::getFormat() const {
  return format;
}

void Vinyl::setFormat(const FormatType &newFormat) {
  format = newFormat;
}

Vinyl::SpeedType Vinyl::getSpeed() const {
  return speed;
}

void Vinyl::setSpeed(const SpeedType &newSpeed) {
  speed = newSpeed;
}

string Vinyl::getFormatAsString() const {
  switch (format) {
    case Twelve:
      return "12";
    case Ten:
      return "10";
    case Seven:
      return "7";
    default:
      return "Unknown";
  }
}

string Vinyl::getSpeedAsString() const {
  switch (speed) {
    case ThirtyThree:
      return "33";
    case FortyFive:
      return "45";
    default:
      return "Unknown";
  }
}
