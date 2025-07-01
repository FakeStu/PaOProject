#ifndef JSONIMPORTVISITOR_H
#define JSONIMPORTVISITOR_H

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include "../Import.h"
#include "../../../Factory/JSON/JsonProductFactory.h"
#include "../../../Factory/JSON/Factories/JsonBookFactory.h"
#include "../../../Factory/JSON/Factories/JsonCDFactory.h"
#include "../../../Factory/JSON/Factories/JsonComicFactory.h"
#include "../../../Factory/JSON/Factories/JsonMagazineFactory.h"
#include "../../../Factory/JSON/Factories/JsonMovieFactory.h"
#include "../../../Factory/JSON/Factories/JsonVinylFactory.h"

class JsonImport : public Import {
private:
  std::unordered_map<std::string, std::unique_ptr<JsonProductFactory> > _factories;

  std::shared_ptr<Product> createFromJson(const QJsonObject &obj, const QString &type);

public:
  JsonImport() {
    _factories["book"] = std::make_unique<JsonBookFactory>();
    _factories["magazine"] = std::make_unique<JsonMagazineFactory>();
    _factories["comic"] = std::make_unique<JsonComicFactory>();
    _factories["cd"] = std::make_unique<JsonCDFactory>();
    _factories["vinyl"] = std::make_unique<JsonVinylFactory>();
    _factories["movie"] = std::make_unique<JsonMovieFactory>();
  };
  std::vector<std::shared_ptr<Product> > importFromFile(const QString &filename);
};
#endif
