////
//// Created by 31838 on 9/23/2019.
////
//
////#include "common.h"
//#include <iostream>
//#include <vector>
//#include <string>
//
//auto main() -> int {
//  auto n = Input<uint32_t>(std::cin);
//  std::vector<uint32_t> res{};
//  for (uint32_t i = 0; i <= n; i++) {
//    auto numStr = std::to_string(i);
//    if (numStr.find('7' + '0') != std::string::npos || i % 7 == 0)
//      res.push_back(i);
//  }
//
//  std::cout << res << std::endl;
//  return EXIT_SUCCESS;
//}

#include <iostream>
#include <string>
#include "common.h"

auto main() -> int {
  auto n = Input<uint32_t>(std::cin);
  std::vector<uint32_t> res{};
  for (uint32_t i = 0; i <= n; i++) {
    if (std::to_string(i).find(7 + '0') != std::string::npos || i % 7 == 0)
      res.push_back(i);
  }
  std::cout << res << std::endl;
  return EXIT_SUCCESS;
}
