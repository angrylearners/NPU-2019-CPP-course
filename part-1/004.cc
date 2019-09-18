//
// Created by 31838 on 9/18/2019.
//

#include <array>
#include <iostream>
#include <algorithm>

auto main() -> int {
  std::array<int64_t, 3> numbers = std::array<int64_t, 3>();
  std::cin >> numbers[0] >> numbers[1] >> numbers[2];
  std::sort(std::begin(numbers), std::end(numbers));
  std::cout << numbers[2] << std::endl;
  return EXIT_SUCCESS;
}