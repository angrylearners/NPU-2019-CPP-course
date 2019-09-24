//
// Created by 31838 on 9/23/2019.
//

#include <cmath>
#include <iostream>
#include "common.h"

auto main() -> int {
  const auto n = Input<uint32_t>(std::cin);
  const auto m = Input<uint32_t>(std::cin);
  
  double a{}, b{};
  
  for (uint32_t i = m + 1; i <= n; i++)
    a += log(i);
  
  for (uint32_t i = 2; i <= n - m; i++)
    b += log(i);
  
  std::cout << (uint32_t) round(exp(a - b)) << std::endl;
  return EXIT_SUCCESS;
}
