//
// Created by 31838 on 9/23/2019.
//

#ifndef PART_5_COMMON_H
#define PART_5_COMMON_H

#include <ios>
#include <valarray>

template<typename T>
auto InputArray(std::istream &is) -> std::valarray<T> {
  size_t nums{};
  is >> nums;
  
  auto res = std::valarray<T>(nums);
  
  for (size_t i = 0; i < nums; i++)
    is >> res[i];
  
  return res;
}

template<typename T>
auto InputArray(std::istream &is, size_t nums) -> std::valarray<T> {
  auto res = std::valarray<T>(nums);
  
  for (size_t i = 0; i < nums; i++)
    is >> res[i];
  
  return res;
}

template<typename T>
auto Input(std::istream &is) -> T {
  T res{};
  is >> res;
  return res;
}

template<typename T>
auto InputSquareMatrix(std::istream &is) -> std::valarray<std::valarray<T>> {
  size_t a{};
  is >> a;
  
  auto res = std::valarray<std::valarray<T>>(a);
  
  for (size_t i = 0; i < a; i++) {
    res[i] = std::valarray<T>(a);
    for (size_t j = 0; j < a; j++)
      is >> res[i][j];
  }
  
  return res;
}

#endif //PART_5_COMMON_H
