#ifndef XMLIMPORT_H
#define XMLIMPORT_H

#include <memory>
#include <qdom.h>
#include "../Import.h"
#include "../../../Factory/XML/XmlProductFactory.h"
#include "../../../Factory/XML/Factories/XmlBookFactory.h"
#include "../../../Factory/XML/Factories/XmlCDFactory.h"
#include "../../../Factory/XML/Factories/XmlComicFactory.h"
#include "../../../Factory/XML/Factories/XmlMagazineFactory.h"
#include "../../../Factory/XML/Factories/XmlMovieFactory.h"
#include "../../../Factory/XML/Factories/XmlVinylFactory.h"

class XmlImport : public Import {
private:
  std::unordered_map<std::string, std::unique_ptr<XmlProductFactory> > _factories;

  std::shared_ptr<Product> createFromXml(const QDomElement &obj, const QString &type);

public:
  XmlImport() {
    _factories["book"] = std::make_unique<XmlBookFactory>();
    _factories["magazine"] = std::make_unique<XmlMagazineFactory>();
    _factories["comic"] = std::make_unique<XmlComicFactory>();
    _factories["cd"] = std::make_unique<XmlCDFactory>();
    _factories["vinyl"] = std::make_unique<XmlVinylFactory>();
    _factories["movie"] = std::make_unique<XmlMovieFactory>();
  };
  std::vector<std::shared_ptr<Product> > importFromFile(const QString &filename);
};

#endif
