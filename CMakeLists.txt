cmake_minimum_required(VERSION 3.10)
include_directories(${CMAKE_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 14)

project(ProductManage)

add_executable(productManage
  src/main.cpp
  src/Product.cpp
  src/ProductFactory.cpp)
