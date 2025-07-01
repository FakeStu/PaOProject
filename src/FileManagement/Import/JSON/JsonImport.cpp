#include "JsonImport.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

#include "../../../Model/Book.h"
#include "../../../Model/CD.h"
#include "../../../Model/Comic.h"
#include "../../../Model/Magazine.h"
#include "../../../Model/Movie.h"
#include "../../../Model/Vinyl.h"

std::shared_ptr<Product> JsonImport::createFromJson(const QJsonObject &obj, const QString &type) {
  if (obj.isEmpty())
    return nullptr;

  auto it = _factories.find(type.toLower().toStdString());
  if (it == _factories.end()) {
    return nullptr;
  }

  try {
    return it->second->createProduct(obj);
  } catch (const std::exception &e) {
    QMessageBox::warning(nullptr, "Error", e.what());
    return nullptr;
  }
}

std::vector<std::shared_ptr<Product> > JsonImport::importFromFile(const QString &filename) {
  // Vector of products to return
  std::vector<std::shared_ptr<Product> > importedProducts;

  // Access to the file
  QFile file(filename);
  if (!file.open(QIODevice::ReadOnly)) {
    throw std::runtime_error("Cannot open file");
  }

  // Read the file content
  const QByteArray data = file.readAll();
  file.close();

  // Parse the JSON data
  const QJsonDocument doc = QJsonDocument::fromJson(data);
  if (!doc.isObject()) {
    throw std::runtime_error("Invalid JSON format");
  }

  // Get the root object
  QJsonObject root = doc.object();
  if (!root.contains("products")) {
    throw std::runtime_error("Missing 'products' object in JSON");
  }

  QJsonObject products = root["products"].toObject();

  // Iterate through the products
  for (const auto key: products.keys()) {
    for (const QJsonValue &jsonProduct: products[key].toArray()) {
      if (jsonProduct.isObject()) {
        auto obj = jsonProduct.toObject();
        std::shared_ptr<Product> product = createFromJson(obj, key);
        if (product) {
          importedProducts.push_back(product);
        }
      }
    }
  }

  return importedProducts;
}
