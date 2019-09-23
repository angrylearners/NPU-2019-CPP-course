//
// Created by 31838 on 9/18/2019.
//

#include <iostream>
#include <cassert>

inline auto InRange(uint32_t val, uint32_t from, uint32_t to) -> bool {
  return from <= val && val <= to;
}

auto main() -> int {
  uint16_t grade{};
  std::cin >> grade;
  assert(0 <= grade && grade <= 100);
  
  char convertedGrade = '\0';

//  switch (grade) {
//    case 90 ... 100:
//      convertedGrade = 'A';
//    case 80 ... 89:
//      convertedGrade = 'B';
//    case 70 ... 79:
//      convertedGrade = 'C';
//    case 60 ... 69:
//      convertedGrade = 'D';
//    default:
//      convertedGrade = 'E';
//  }
//
  
  if (InRange(grade, 90, 100))
    convertedGrade = 'A';
  else if (InRange(grade, 80, 90))
    convertedGrade = 'B';
  else if (InRange(grade, 70, 79))
    convertedGrade = 'C';
  else if (InRange(grade, 60, 69))
    convertedGrade = 'D';
  else
    convertedGrade = 'E';
  
  std::cout << convertedGrade << std::endl;
  return EXIT_SUCCESS;
}