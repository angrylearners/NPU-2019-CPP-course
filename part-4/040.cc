//
// Created by 31838 on 9/23/2019.
//

#include <string>
#include <iostream>
#include <vector>

auto main() -> int {
  std::string original{};
  std::cin >> original;
  std::vector<char> reversed{};
  for (auto ch:original)
    reversed.insert(reversed.begin(), ch);
  for (auto ch:reversed)
    std::cout << ch;
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
