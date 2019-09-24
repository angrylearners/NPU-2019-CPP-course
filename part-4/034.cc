//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include "common.h"

auto Fun(double x, double a0, double a1 = 0, double a2 = 0, double a3 = 0) -> double {
  return a0 + a1 * x + a2 * x * x + a3 * x * x * x;
}

auto Fun(double x, const std::valarray<double> &as) -> double {
  if (as.size() == 1)
    return Fun(x, as[0]);
  else if (as.size() == 2)
    return Fun(x, as[0], as[1]);
  else if (as.size() == 3)
    return Fun(x, as[0], as[1], as[2]);
  else
    return Fun(x, as[0], as[1], as[2], as[3]);
}

auto main() -> int {
  auto x = Input<double>(std::cin);
  auto n = Input<uint32_t>(std::cin);
  
  auto as = InputArray<double>(std::cin, n + 1);
  
  std::cout << Fun(x, as) << std::endl;
  return EXIT_SUCCESS;
}
