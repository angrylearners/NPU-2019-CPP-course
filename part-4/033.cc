//
// Created by 31838 on 9/23/2019.
//

#include <vector>
#include <iostream>
#include "common.h"

auto Find(uint32_t number) -> std::vector<uint32_t> {
  std::vector<uint32_t> res{};
  for (uint32_t i = 1; i <= number / 2; i++)
    if (number % i == 0)
      res.push_back(i);
  return res;
}

auto SumVector(const std::vector<uint32_t> &vec) -> uint64_t {
  uint64_t res{};
  for (auto iter : vec)
    res += iter;
  return res;
}

auto main() -> int {
  auto a = Input<uint32_t>(std::cin);
  auto b = Input<uint32_t>(std::cin);
  
  if (SumVector(Find(a)) == b && SumVector(Find(b)) == a)
    std::cout << "yes";
  else
    std::cout << "no";
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
