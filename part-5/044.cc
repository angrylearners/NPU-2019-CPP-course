//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include "common.h"

auto main() -> int {
  auto matrix = InputSquareMatrix<int32_t>(std::cin);
  for (size_t row = 0; row < matrix.size(); row++) {
    for (size_t i = 0; i < matrix.size() - 1 - row; i++)
      std::cout << "  ";
    for (size_t col = matrix.size() - 1 - row; col < matrix.size(); col++)
      std::cout << matrix[row][col] << " ";
    std::cout << std::endl;
  }
  return EXIT_SUCCESS;
}