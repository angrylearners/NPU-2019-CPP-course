//
// Created by 31838 on 9/18/2019.
//

#include <iostream>
#include <iomanip>
#include <cassert>

auto ConvertDistance(double distance) -> double {
  if (distance == (uint64_t) distance)
    return distance;
  return double(uint64_t(distance) + 1);
}

auto Calc(double distance) -> double {
  assert(distance >= 0);
  distance = ConvertDistance(distance);
  if (distance <= 2)return 7;
  if (2 < distance && distance <= 15)return (double) (distance - 2) * 1.5 + Calc(2);
  if (15 < distance)return (distance - 15) * 2.1 + Calc(15);
  throw std::runtime_error("unreachable code");
}

auto main() -> int {
  double distance{};
  std::cin >> distance;
  std::cout << std::fixed << std::setprecision(6) <<
            Calc(distance)
            << std::endl;
  return EXIT_SUCCESS;
}