//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include "common.h"

auto Solution(uint32_t val) -> size_t {
  size_t res{};

#define apply(N)                                                               \
  do {                                                                         \
    res += val / N;                                                            \
    val %= N;                                                                  \
    if (!val)                                                                  \
      return res;                                                              \
  } while (0)
  
  apply(100);
  apply(50);
  apply(20);
  apply(10);
  apply(5);
  apply(2);
#undef apply
  return res + 1;
}

auto main() -> int {
  std::cout << Solution(Input<uint32_t>(std::cin)) << std::endl;
  return EXIT_SUCCESS;
}
