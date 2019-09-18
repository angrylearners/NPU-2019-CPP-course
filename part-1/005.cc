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
  std::cout <<
            ((std::stoll(original) == std::stoll(reversed)) ? "yes" : "no")
            << std::endl;
  return EXIT_SUCCESS;
}