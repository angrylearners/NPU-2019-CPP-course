//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include "common.h"

auto main() -> int {
  auto input = InputArray<char, 4>(std::cin);
  for (auto &v:input)
    v = ((v - '0') + 5) % 10 + '0';
  std::swap(input[0], input[3]);
  std::swap(input[1], input[2]);
  
  for (const auto &v:input)
    std::cout << v;
  std::cout << std::endl;
  return EXIT_SUCCESS;
}


