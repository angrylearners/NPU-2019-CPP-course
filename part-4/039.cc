//
// Created by 31838 on 9/23/2019.
//

#include <queue>
#include <iostream>
#include "common.h"

auto main() -> int {
  auto num = Input<uint64_t>(std::cin);
  auto shift = Input<int64_t>(std::cin);
  
  std::vector<char> digits{};
  
  while (num > 0) {
    auto ch = (char) ((num % 10) + '0');
    digits.push_back(ch);
    num /= 10;
  }
  
  if (shift < 0)
    for (uint64_t i = 0; i < -1 * shift; i++) {
      auto front = digits.front();
      digits.erase(digits.begin());
      digits.push_back(front);
    }
  else if (shift > 0)
    for (uint64_t i = 0; i < shift; i++) {
      auto back = digits.back();
      digits.erase(digits.end() - 1);
      digits.insert(digits.begin(), back);
    }
  
  for (auto v:digits)
    std::cout << v;
  std::cout << std::endl;
  return EXIT_SUCCESS;
}

