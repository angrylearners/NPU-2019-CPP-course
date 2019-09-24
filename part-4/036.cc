//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include <common.h>

auto GetFloor(double x) -> int64_t {
  return (int64_t) x;
}

auto main() -> int {
  std::cout << GetFloor(Input<double>(std::cin)) << std::endl;
  return EXIT_SUCCESS;
}
