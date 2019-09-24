//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include "common.h"

auto ack(uint32_t m, uint32_t n) -> uint64_t {
  if (!m)
    return n + 1;
  if (!n)
    return ack(m - 1, 1);
  return ack(m - 1, ack(m, n - 1));
}

auto main() -> int {
  auto m = Input<uint32_t>(std::cin);
  auto n = Input<uint32_t>(std::cin);
  
  std::cout << ack(m, n) << std::endl;
  return EXIT_SUCCESS;
}
