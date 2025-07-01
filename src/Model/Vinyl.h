#ifndef VINYL_H
#define VINYL_H
#include "Disk.h"
#include <string>
using std::string;

class ProductVisitor;

class Vinyl : public Disk {
public:
  enum FormatType { Twelve, Ten, Seven };
  static FormatType formatFromString(const string &format) {
    if (format == "Twelve")
      return FormatType::Twelve;
    else if (format == "Ten")
      return FormatType::Ten;
    else if (format == "Seven")
      return FormatType::Seven;
    else
      throw std::invalid_argument("Invalid format type");
  }

  enum SpeedType { ThirtyThree, FortyFive };
  static SpeedType speedFromString(const string &speed) {
    if (speed == "ThirtyThree")
      return SpeedType::ThirtyThree;
    else if (speed == "FortyFive")
      return SpeedType::FortyFive;
    else
      throw std::invalid_argument("Invalid speed type");
  }

private:
  string color;
  FormatType format;
  SpeedType speed;

public:
  Vinyl(string name,
        double price,
        QDateTime date,
        int totalCopies,
        string image,
        string artist,
        string publisher,
        int duration,
        string color,
        FormatType format,
        SpeedType speed);

  virtual ~Vinyl() = default;
  virtual void accept(ProductVisitor &visitor);
  string getColor() const;
  void setColor(const string &color);
  FormatType getFormat() const;
  string getFormatAsString() const;
  SpeedType getSpeed() const;
  string getSpeedAsString() const;
  void setFormat(const FormatType &format);
  void setFormatFromString(const string &format);
  void setSpeed(const SpeedType &speed);
  void setSpeedFromString(const string &speed);
};
#endif
