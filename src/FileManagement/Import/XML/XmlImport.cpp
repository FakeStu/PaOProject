#include "XmlImport.h"
#include <QDateTime>
#include <QFile>
#include <QMessageBox>

std::shared_ptr<Product> XmlImport::createFromXml(const QDomElement &obj, const QString &type) {
  if (obj.isNull())
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

std::vector<std::shared_ptr<Product> > XmlImport::importFromFile(const QString &filename) {
  // Vector of products to return
  std::vector<std::shared_ptr<Product> > importedProducts;

  // Access to the file
  QFile file(filename);
  if (!file.open(QIODevice::ReadOnly)) {
    throw std::runtime_error("Cannot open file");
  }

  // Parse the XML content
  QDomDocument doc;
  if (!doc.setContent(&file)) {
    throw std::runtime_error("Invalid XML format");
  }

  // Get the root element
  QDomElement root = doc.documentElement();
  if (root.tagName() != "products") {
    throw std::runtime_error("Missing 'products' element in XML");
  }


  // Iterate through the products
  QDomElement product = root.firstChildElement();
  while (!product.isNull()) {
    QString type = product.tagName();
    std::shared_ptr<Product> prod = createFromXml(product, type);
    if (prod) {
      importedProducts.push_back(prod);
    }
    product = product.nextSiblingElement();
  }

  return importedProducts;
}
