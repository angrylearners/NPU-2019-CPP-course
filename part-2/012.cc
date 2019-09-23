//
// Created by 31838 on 9/18/2019.
//

#include <iostream>
#include <array>

//  A B C
const std::array<std::array<bool, 3>, 3> PossibleMap = {
  std::array<bool, 3>{false, true, false}, // X
  std::array<bool, 3>{true, true, true},  // Y
  std::array<bool, 3>{true, true, false}  // Z
};

auto GetTeamBMemberIdentifier(int index) -> char {
  const std::array<char, 3> members = {'X', 'Y', 'Z'};
  return members[index];
}

auto main() -> int {
  for (auto i = 0; i < 3; i++)
    if (PossibleMap[i][0])
      for (auto j = 0; j < 3; j++)
        if (PossibleMap[j][1])
          for (auto k = 0; k < 3; k++)
            if (PossibleMap[k][2])
              if (i != j && j != k && i != k) {
                std::cout << 'A' << "=>" << GetTeamBMemberIdentifier(i) << std::endl;
                std::cout << 'B' << "=>" << GetTeamBMemberIdentifier(j) << std::endl;
                std::cout << 'C' << "=>" << GetTeamBMemberIdentifier(k) << std::endl;
                return EXIT_SUCCESS;
              }
  throw std::runtime_error("no solution");
}