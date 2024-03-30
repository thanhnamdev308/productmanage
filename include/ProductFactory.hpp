// Copyright 2022 NguyenThanhNam [legal/copyright]
#ifndef PRODUCT_FACTORY_HPP_
#define PRODUCT_FACTORY_HPP_

#include <string.h>

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

#include "include/Product.hpp"

class ProductFactory {
 public:
  // Function to create Product' from a string
  Product *createProduct(const std::string &s);
  // Function to create a list of Product from .csv file
  std::list<Product *> readProductFromFile(const std::string &filename);
  // Function to save Product to 3 files .txt
  void saveProductToFile(const std::list<Product *> &Product);
  // Function to export a .csv type of Product sorted by expired date
  void exportSortedProduct(std::list<Product *> product);
};

bool compareExpiredDate(Product *a, Product *b);

#endif  // PRODUCT_FACTORY_HPP_
