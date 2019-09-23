//
// Created by 31838 on 9/23/2019.
//

#include <vector>
#include <iostream>
#include "common.h"

template<typename T>
auto SelectionSort(std::vector<T> vec) -> std::vector<T> {
  std::vector<T> res{};
  while (!vec.empty()) {
    auto biggest = vec.begin();
    for (auto i = vec.begin(); i != vec.end(); i++)
      if (*i > *biggest)
        biggest = i;
    res.push_back(*biggest);
    vec.erase(biggest);
  }
  return res;
}

auto main() -> int {
  auto vec = InputVector<int32_t>(std::cin);
  auto s = Input<uint32_t>(std::cin);
  auto m = Input<uint32_t>(std::cin);
  std::vector<uint32_t> toSort{};
  toSort.resize(m);
  for (auto i = s; i < s + m; i++)
    toSort.push_back(vec[i]);
  auto sorted = SelectionSort(toSort);
  std::copy(sorted.begin(), sorted.end(), vec.begin() + s);
  std::cout << vec << std::endl;
}