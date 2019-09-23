//
// Created by 31838 on 9/23/2019.
//

#include <iostream>
#include <tuple>

#include "common.h"

using Data=std::tuple<size_t/*index*/, int32_t /*data*/>;
using Result=std::tuple<bool/*found?*/, size_t /*index*/>;

auto ProcessOriginalArray(const std::valarray<int32_t> &ori) -> std::valarray<Data> {
  auto res = std::valarray<Data>(ori.size());
  for (size_t i = 0; i < ori.size(); i++)
    res[i] = std::make_tuple(i, ori[i]);
  return res;
}

auto Find(std::valarray<Data> arr, int32_t target) -> Result {
  if (target < std::get<1>(arr[0]) || std::get<1>(arr[arr.size() - 1]) < target)
    return std::make_tuple(false, 0);
  
  auto mid = arr[arr.size() / 2];
  auto midData = std::get<1>(mid);
  
  if (arr.size() == 1 && midData != target)
    return std::make_tuple(false, 0);
  
  if (midData == target)
    return std::make_tuple(true, std::get<0>(mid));
  else if (target < midData)
    return Find(arr[std::slice(0, arr.size() / 2, 1)], target);
  else
    return Find(arr[std::slice(arr.size() / 2 + 1,
                               arr.size() % 2 == 0 ? arr.size() / 2 - 1 : arr.size() / 2, 1)],
                target);
}

auto main() -> int {
  auto arr = ProcessOriginalArray(InputArray<int32_t>(std::cin));
  auto target = Input<int32_t>(std::cin);
  
  auto res = Find(arr, target);
  
  if (std::get<0>(res))
    std::cout << std::get<1>(res);
  else
    std::cout << "null";
  
  std::cout << std::endl;
  return EXIT_SUCCESS;
}

