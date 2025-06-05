#ifndef VINYL_H
#define VINYL_H
#include "Disk.h"
#include <string>
using std::string;

class Vinyl : public Disk {
public:
  enum FormatType { Twelve, Ten, Seven };

  enum SpeedType { ThirtyThree, FortyFive };

private:
  string color;
  FormatType format;
  SpeedType speed;

public:
  Vinyl(string name, double price, QDateTime date, int totalCopies,
        string image, string artist, string publisher, int duration,
        string color, FormatType format, SpeedType speed);

  virtual ~Vinyl() = default;

  string getColor() const;
  FormatType getFormat() const;
  SpeedType getSpeed() const;
  void setColor(const string &color);
  void setFormat(const FormatType &format);
  void setSpeed(const SpeedType &speed);
  string getFormatAsString() const;
  string getSpeedAsString() const;
};
#endif //VINYL_H
