//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include <cmath>
#include <string>
#include "common.h"

auto main() -> int {
  auto m = Input<uint32_t>(std::cin);
  auto n = Input<uint32_t>(std::cin);
  
  uint32_t g{};
  uint64_t s{};
  
  for (uint32_t i = pow(10, n - 1); i < pow(10, n); i++) {
    auto strNum = std::to_string(i);
    if (strNum.find(m + '0') == std::string::npos || i % m == 0)
      continue;
    
    g++;
    s += i;
  }
  
  std::cout << g << " " << s << std::endl;
  return EXIT_SUCCESS;
}
