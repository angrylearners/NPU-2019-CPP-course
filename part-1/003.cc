//
// Created by 31838 on 9/18/2019.
//

#include <iostream>
#include <iomanip>

auto main() -> int {
  uint64_t math{}, english{}, c{};
  std::cin >> math >> english >> c;
  std::cout << std::fixed << std::setprecision(6) <<
            (double) (math + english + c)
            << std::endl <<
            (double) (math + english + c) / (double) 3
            << std::endl;
  return EXIT_SUCCESS;
}