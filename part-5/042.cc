//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include "common.h"

auto main() -> int {
  size_t num{};
  std::cin >> num;
  
  auto arrA = InputArray<int32_t>(std::cin, num);
  auto arrB = InputArray<int32_t>(std::cin, num);
  
  arrA += arrB;
  std::cout << arrA << std::endl;
}