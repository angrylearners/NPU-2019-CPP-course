//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include "common.h"

auto main() -> int {
  auto matrix = InputSquareMatrix<int32_t>(std::cin);
  for (size_t row = 0; row < matrix.size(); row++) {
    for (size_t col = 0; col < matrix.size() - row; col++)
      std::cout << matrix[row][col] << " ";
    std::cout << std::endl;
  }
  return EXIT_SUCCESS;
}