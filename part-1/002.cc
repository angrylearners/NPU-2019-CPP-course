#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  double_t r{}, h{};
  std::cin >> r >> h;
  std::cout << std::fixed << std::setprecision(2) <<
            2 * M_PI * r // 2*PI*r
            << std::endl <<
            M_PI * std::pow(r, 2) // PI*r^2
            << std::endl <<
            4 * M_PI * std::pow(r, 2) // 4*PI*r^2
            << std::endl <<
            (double) 4 / (double) 3 * M_PI * std::pow(r, 3) // 4/3*PI*r^2
            << std::endl <<
            M_PI * std::pow(r, 2) * h // PI*r^2*h
            << std::endl;
  return EXIT_SUCCESS;
}