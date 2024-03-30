// Copyright 2022 NguyenThanhNam [legal/copyright]
#include "include/ProductFactory.hpp"

// Function to remove space in the beginning and the end of a string
std::string trimString(const std::string &s) {
  std::string temp = s;
  int n = s.size();
  int end;
  int i = 0;

  // Remove all space in the beginning of the string
  while (isspace(temp[i])) {
    temp.erase(i, 1);
  }

  // If removed all characters, return the string
  if (temp[i] == 0) {
    return temp;
  }

  // Remove all space in the end of the string
  end = n - 1;
  while (end > i && isspace(temp[end])) {
    temp.erase(end, 1);
  }

  temp[n] = '\0';
  return temp;
}

Product *ProductFactory::createProduct(const std::string &s) {
  std::string temp = s;
  std::vector<std::string> data;
  std::istringstream stream(temp);
  std::string count;

  while (stream >> count) {
    // When found ',' save the word to data vector
    int pos = temp.find(",");
    std::string token = temp.substr(0, pos);

    // Remove all spaces then save the word to data vector
    data.push_back(trimString(token));

    // Remove the saved word to get the next word
    temp.erase(0, pos + 1);
  }

  return new Product(data[0], data[1], data[2], data[3], data[4], data[5]);
}

std::list<Product *> ProductFactory::readProductFromFile(
    const std::string &filename) {
  std::list<Product *> productList;
  std::string line;
  std::ifstream file(filename);

  // Check if the file is opened successfully
  if (!file.is_open()) {
    std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
  }

  // Loop to save all Product objects to the list
  int i = 1;
  while (getline(file, line)) {
    // Skip the first row since it is not of the right form
    if (i == 1) {
      i++;
      continue;
    }

    Product *Product = createProduct(line);
    if (Product) {
      productList.push_back(Product);
    }

    // Print the date of Product to see if the date is valid or not
    Product->printData();
    std::cout << std::endl;
  }

  // Close the file
  file.close();

  return productList;
}

void ProductFactory::saveProductToFile(
    const std::list<Product *> &productList) {
  // Save the file of food category
  std::ofstream myFile1("Food.txt");
  for (auto i : productList) {
    if (i->classifyProduct() == "Food") {
      myFile1 << i->toString() << std::endl;
    }
  }

  // Save the file of drink category
  std::ofstream myFile2("Drink.txt");
  for (auto i : productList) {
    if (i->classifyProduct() == "Drink") {
      myFile2 << i->toString() << std::endl;
    }
  }

  // Save the file of utensil category
  std::ofstream myFile3("Utensil.txt");
  for (auto i : productList) {
    if (i->classifyProduct() == "Utensil") {
      myFile3 << i->toString() << std::endl;
    }
  }

  // Close all files
  myFile1.close();
  myFile2.close();
  myFile3.close();
}

bool compareExpiredDate(Product *a, Product *b) {
  std::string date1 = a->m_ExpiredDate;
  int day1 = stoi(date1.substr(0, 2));
  int month1 = stoi(date1.substr(2, 2));
  int year1 = stoi(date1.substr(4, 4));

  std::string date2 = b->m_ExpiredDate;
  int day2 = stoi(date2.substr(0, 2));
  int month2 = stoi(date2.substr(2, 2));
  int year2 = stoi(date2.substr(4, 4));

  // All cases when true should be returned
  if (year1 < year2) {
    return true;
  }
  if (year1 == year2 && month1 < month2) {
    return true;
  }
  if (year1 == year2 && month1 == month2 && day1 < day2) {
    return true;
  }

  // If none of the above cases satisfy, return false
  return false;
}

void ProductFactory::exportSortedProduct(std::list<Product *> productList) {
  productList.sort(compareExpiredDate);
  // Save the file of sorted product list
  std::ofstream myFile1("sortedProductList.csv");
  for (auto i : productList) {
    myFile1 << i->toString() << std::endl;
  }
  myFile1.close();
}
