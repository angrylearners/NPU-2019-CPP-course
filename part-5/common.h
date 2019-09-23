//
// Created by 31838 on 9/23/2019.
//

#ifndef PART_5_COMMON_H
#define PART_5_COMMON_H

#include <ios>
#include <valarray>
#include <vector>

template<typename T>
auto InputArray(std::istream &is) -> std::valarray<T> {
  size_t num{};
  is >> num;
  
  auto res = std::valarray<T>(num);
  
  for (size_t i = 0; i < num; i++)
    is >> res[i];
  
  return res;
}

template<typename T>
auto InputVector(std::istream &is) -> std::vector<T> {
  auto arr = InputArray<T>(is);
  std::vector<T> res{};
  for (size_t i = 0; i < arr.size(); i++)
    res.push_back(arr[i]);
  return res;
}

template<typename T>
auto InputArray(std::istream &is, size_t len) -> std::valarray<T> {
  auto res = std::valarray<T>(len);
  
  for (size_t i = 0; i < len; i++)
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

template<typename T>
auto operator<<(std::ostream &os, const std::valarray<T> &arr) -> std::ostream & {
  for (size_t i = 0; i < arr.size(); i++)
    os << arr[i] << " ";
  return os;
}

template<typename T>
auto operator<<(std::ostream &os, const std::vector<T> &arr) -> std::ostream & {
  for (size_t i = 0; i < arr.size(); i++)
    os << arr[i] << " ";
  return os;
}

#endif //PART_5_COMMON_H
