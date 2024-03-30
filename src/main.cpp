// Copyright 2022 NguyenThanhNam [legal/copyright]

#include "include/ProductFactory.hpp"

int main() {
  ProductFactory Factory;
  std::list<Product *> productList;

  productList = Factory.readProductFromFile("../input.csv");
  Factory.saveProductToFile(productList);
  Factory.exportSortedProduct(productList);

  // Destroy object
  while (productList.size()) {
    Product *temp = productList.front();
    productList.pop_front();
    delete temp;
    temp = nullptr;
  }
  
  return 0;
}
