//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include "common.h"

auto main() -> int {
  auto arrA = InputArray<int32_t>(std::cin);
  auto arrB = std::valarray<int32_t>(arrA.size());
  
  std::copy(std::begin(arrA), std::end(arrA), std::begin(arrB));
  
  for (size_t i = 1; i < arrB.size(); i += 2)
    std::cout << arrB[i] << " ";
  
  std::cout << std::endl;
  return EXIT_SUCCESS;
}