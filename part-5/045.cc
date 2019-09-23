//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include "common.h"

auto main() -> int {
  auto numTentacle = Input<uint32_t>(std::cin);
  auto numSpongeBob = Input<uint32_t>(std::cin);
  
  auto dTentacles = InputArray<uint32_t>(std::cin, numTentacle);
  auto pSpongeBobs = InputArray<uint32_t>(std::cin, numSpongeBob);
  
  std::sort(std::begin(dTentacles), std::end(dTentacles));
  std::sort(std::begin(pSpongeBobs), std::end(pSpongeBobs));
  
  auto res = std::valarray<uint32_t>(numTentacle);
  
  for (size_t i = 0, j = 0; i < numTentacle; i++) {
    for (; j < numSpongeBob; j++) {
      if (dTentacles[i] <= pSpongeBobs[j]) {
        res[i] = pSpongeBobs[j];
        break;
      }
    }
  }
  
  std::cout << res.sum() << std::endl;
  
  return EXIT_SUCCESS;
}