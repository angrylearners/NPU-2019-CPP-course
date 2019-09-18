//
// Created by 31838 on 9/18/2019.
//

#include <iostream>
#include <cassert>

auto ShowAndExit(char ch) -> void {
  std::cout << ch << std::endl;
  exit(EXIT_SUCCESS);
}

auto main() -> int {
  uint16_t grade{};
  std::cin >> grade;
  assert(0 <= grade && grade <= 100);
  switch (grade) {
    case 90 ... 100:
      ShowAndExit('A');
    case 80 ... 89:
      ShowAndExit('B');
    case 70 ... 79:
      ShowAndExit('C');
    case 60 ... 69:
      ShowAndExit('D');
    default:
      ShowAndExit('E');
  }
  throw std::runtime_error("unreachable code");
}