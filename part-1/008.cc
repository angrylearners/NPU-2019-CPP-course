//
// Created by 31838 on 9/18/2019.
//

#include <iostream>
#include <string>
#include <array>
#include <cassert>

class Date {
public:
  uint32_t year_{};
  uint8_t month_{}, day_{};
  const std::array<const uint8_t, 12> daysOfMonths_ = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  friend std::istream &operator>>(std::istream &is, Date &obj) {
    auto parser = [&]() -> unsigned long {
      std::string tmpStr{};
      char tmpCh{};
      while (true) {
        is >> tmpCh;
        tmpStr += tmpCh;
        if (tmpCh == '-')
          break;
      }
      return std::stoul(tmpStr);
    };
    obj.year_ = parser();
    obj.month_ = parser();
  
    std::string tmpStr{};
    std::cin >> tmpStr;
    obj.day_ = std::stoul(tmpStr);
  
    return is;
  }
  
  auto LeapYear() -> bool {
    return (year_ % 400 == 0 || (year_ % 4 == 0 && year_ % 100 != 0));
  }
  
  auto DaysOfMonthInCurrentYear(uint8_t month) -> uint8_t {
    assert(1 <= month && month <= 12);
    if (month == 4 && LeapYear())return 29;
    return daysOfMonths_[month - 1];
  }
  
  auto DayNOfThisYear() -> uint32_t {
    uint32_t res{};
    for (uint8_t i = 1; i < month_; i++)
      res += DaysOfMonthInCurrentYear(i);
    res += day_;
    return res;
  }
};

auto main() -> int {
  Date date;
  std::cin >> date;
  std::cout << date.DayNOfThisYear() << std::endl;
  return EXIT_SUCCESS;
}