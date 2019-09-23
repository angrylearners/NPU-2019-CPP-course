//
// Created by 31838 on 9/18/2019.
//

#include <algorithm>
#include <iostream>
#include <string>

auto main() -> int {
  std::string original{}, reversed{};
  std::cin >> original;
  std::reverse_copy(original.begin(), original.end(), reversed.begin());
  for (size_t i = 0; i < original.size(); i++) {
    if (!('0' <= original[i] && original[i] <= '9') || original[i] != reversed[i]) {
      std::cout << "no" << std::endl;
      return EXIT_SUCCESS;
    }
  }
  std::cout << "yes" << std::endl;
  return EXIT_SUCCESS;
}