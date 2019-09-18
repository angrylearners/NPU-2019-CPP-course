//
// Created by 31838 on 9/18/2019.
//

#include <iostream>
#include <cmath>
#include <array>

struct Position {
  double x, y;
  
  friend std::istream &operator>>(std::istream &is, Position &pos) {
    is >> pos.x;
    is.ignore(1, ',');
    is >> pos.y;
    is.ignore();
    return is;
  }
};

auto InCircle(Position position, Position circle, double radius = 1) -> bool {
  return (std::pow(position.x + circle.x, 2) +
          std::pow(position.y + circle.y, 2))
         <= std::pow(radius, 2);
}


std::array<Position, 4> circles = {
  (Position) {2, 2},
  (Position) {2, -2},
  (Position) {-2, -2},
  (Position) {-2, 2}
};

auto main() -> int {
  Position pos{};
  std::cin >> pos;
  for (const auto &c:circles)
    if (InCircle(pos, c)) {
      std::cout << 10 << std::endl;
      return EXIT_SUCCESS;
    }
  std::cout << 0 << std::endl;
  return EXIT_SUCCESS;
}