// Copyright 2022 NguyenThanhNam [legal/copyright]
#include "include/Product.hpp"

Product::Product(const std::string& category, const std::string& id,
                 const std::string& quantity, const std::string& importDate,
                 const std::string& description, const std::string& expiredDate)
    : m_Category(category),
      m_ID(id),
      m_Quantity(quantity),
      m_ImportDate(importDate),
      m_Description(description),
      m_ExpiredDate(expiredDate) {}

void Product::printData() {
  std::cout << "Category:\t" << m_Category << std::endl;
  std::cout << "ID:\t\t" << m_ID << std::endl;
  std::cout << "Quantity:\t" << m_Quantity << std::endl;
  std::cout << "Import Date:\t" << m_ImportDate;
  if (checkValidDate(m_ImportDate)) {
    std::cout << " -> OK";
  } else {
    std::cout << " -> NG";
  }
  std::cout << std::endl;
  std::cout << "Description:\t" << m_Description << std::endl;
  std::cout << "Expired Date:\t" << m_ExpiredDate;
  if (checkValidDate(m_ExpiredDate)) {
    std::cout << " -> OK";
  } else {
    std::cout << " -> NG";
  }
  std::cout << std::endl;
}

std::string Product::toString() {
  std::string str = m_Category + ", " + m_ID + ", " + m_Quantity + ", " +
                    m_ImportDate + ", " + m_Description + ", " + m_ExpiredDate;
  return str;
}

std::string Product::classifyProduct() {
  if (m_Category == "Food") {
    return "Food";
  }
  if (m_Category == "Drink") {
    return "Drink";
  }
  if (m_Category == "Utensil") {
    return "Utensil";
  }
}

// Check if the given year is a leap year
bool isLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    return true;
  }
  return false;
}

// Count numbers of days in a given month
int countDayInMonth(int month, int year) {
  int numOfDays;
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      numOfDays = 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      numOfDays = 30;
      break;
    case 2:
      if (isLeapYear(year)) {
        numOfDays = 29;
      } else {
        numOfDays = 28;
      }
      break;
  }
  return numOfDays;
}

bool checkValidDate(std::string const& s) {
  int day = stoi(s.substr(0, 2));
  int month = stoi(s.substr(2, 2));
  int year = stoi(s.substr(4, 4));

  if (year < 2022) {
    return false;
  }

  if (month < 1 || month > 12) {
    return false;
  }

  if (day < 1 || day > countDayInMonth(month, year)) {
    return false;
  }

  return true;
}
