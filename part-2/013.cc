//
// Created by 31838 on 9/18/2019.
//

#include <vector>
#include <cstdint>
#include <iostream>
#include <array>
#include <tuple>
#include <valarray>

using Range=std::tuple<uint32_t, uint32_t>;

auto GetRange() -> Range {
  std::array<uint32_t, 2> tmpNums{};
  std::cin >> tmpNums[0] >> tmpNums[1];
  return tmpNums[0] > tmpNums[1] ?
         std::make_tuple(tmpNums[0], tmpNums[1]) :
         std::make_tuple(tmpNums[1], tmpNums[0]);
}

auto MaxInRange(const Range &r) -> uint32_t {
  return std::get<0>(r);
}

auto MinInRange(const Range &r) -> uint32_t {
  return std::get<1>(r);
}

enum class Flag {
  kUnknown,
  kPrime,
  kNotPrime
};

std::valarray<Flag> primeNumbers;

auto PrimeNumber(uint32_t num) -> bool {
  if (primeNumbers[num] != Flag::kUnknown)
    return primeNumbers[num] == Flag::kPrime;
  if (num == 3)
    return true;
  for (uint32_t i = 3; i <= num / 2; i++)
    if (primeNumbers[i] == Flag::kPrime && num % i == 0)
      return false;
  return true;
}

auto main() -> int {
  auto range = GetRange();
  if (MaxInRange(range) == MinInRange(range))
    return EXIT_SUCCESS;
  
  primeNumbers = std::valarray<Flag>(MaxInRange(range));
  std::fill(std::begin(primeNumbers), std::end(primeNumbers), Flag::kUnknown);
  primeNumbers[0] = primeNumbers[1] = Flag::kNotPrime;
  primeNumbers[2] = Flag::kPrime;
  
  for (uint32_t i = 4; i <= MaxInRange(range); i += 2)
    primeNumbers[i] = Flag::kNotPrime;
  
  for (uint32_t i = 3; i <= MaxInRange(range); i++)
    if (primeNumbers[i] == Flag::kUnknown) {
      auto flag = PrimeNumber(i) ? Flag::kPrime : Flag::kNotPrime;
      primeNumbers[i] = flag;
      for (uint32_t j = 2; j * i <= MaxInRange(range); j++)
        primeNumbers[j * i] = Flag::kNotPrime;
    }
  
  for (uint32_t i = MinInRange(range); i <= MaxInRange(range); i++)
    if (primeNumbers[i] == Flag::kPrime)
      std::cout << i << " ";
  
  std::cout << std::endl;
  return EXIT_SUCCESS;
};
