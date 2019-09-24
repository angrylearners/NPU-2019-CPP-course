//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include <iomanip>
#include "common.h"

auto Avg(const std::valarray<int32_t> &a, const size_t s, const size_t e) -> double {
  size_t eleNum = e - s + 1;
  return (double) a[std::slice(s, eleNum, 1)].sum() / (double) eleNum;
}

auto main() -> int {
  auto arr = InputValarray<int32_t>(std::cin);
  
  auto s = Input<size_t>(std::cin), e = Input<size_t>(std::cin);
  
  std::cout << std::fixed << std::setprecision(6)
            << Avg(arr, s, e)
            << std::endl;
  
  return EXIT_SUCCESS;
}