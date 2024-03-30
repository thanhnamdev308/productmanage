// Copyright 2022 NguyenThanhNam [legal/copyright]
#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <iostream>
#include <sstream>
#include <string>

class Product {
 public:
  // Constructor for Product
  Product(const std::string &, const std::string &, const std::string &,
          const std::string &, const std::string &, const std::string &);
  // Function to print Product' data
  void printData();
  // Function to print Product' to string
  std::string toString();
  // Function to classify Product' category
  std::string classifyProduct();
  // Function to compare Product' expired date
  friend bool compareExpiredDate(Product *a, Product *b);

 private:
  std::string m_Category;
  std::string m_ID;
  std::string m_Quantity;
  std::string m_ImportDate;
  std::string m_Description;
  std::string m_ExpiredDate;
};

// Function to check if the date is valid
bool checkValidDate(std::string const &);

#endif  // PRODUCT_HPP_
