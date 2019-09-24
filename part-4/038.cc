//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include <iomanip>
#include "common.h"

auto main() -> int {
  auto n = Input<size_t>(std::cin);
  double s1{}, s2{};
  
  for (size_t i = 0; i < n; i++) {
    auto v = Input<double>(std::cin);
    s1 += v * v;
    s2 += v;
  }
  
  double avg = s2 / n;
  double s3 = 2 * s2 * avg;
  double s4 = n * avg * avg;
  
  std::cout << std::fixed << std::setprecision(6)
            << s1 - s3 + s4 << std::endl;
  return EXIT_SUCCESS;
}
