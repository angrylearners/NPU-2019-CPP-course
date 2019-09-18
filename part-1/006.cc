//
// Created by 31838 on 9/18/2019.
//

#include <iostream>
#include <iomanip>
#include <functional>
#include <tuple>
#include <vector>

using RuleAction=std::tuple<std::function<bool(uint64_t)>, std::function<double(uint64_t)>>;
#define SIMPLE_RULE(RULE) std::function<bool(uint64_t)>([&](uint64_t val)->bool{return RULE;})
#define SIMPLE_ACT(EXPR) std::function<double(uint64_t)>([&](uint64_t val)->double{return EXPR;})
#define MakeRuleAction(rule, expr)      std::make_tuple(SIMPLE_RULE(rule),SIMPLE_ACT(expr))
#define CalcExtra(val, base, weight) (double)(val-base)*(double)weight

auto MatchAndApplyRule(uint64_t val, const std::vector<RuleAction> &rules) -> double {
  for (const auto &r:rules)
    if (std::get<0>(r)(val))
      return std::get<1>(r)(val);
  throw std::runtime_error("No rule matched");
}

auto InRange(uint64_t val, uint64_t from, uint64_t to, bool leftClose = false, bool rightClose = true,
             bool rightInfinite = false) -> bool {
  if (!(leftClose ? from <= val : from < val))return false;
  if (rightInfinite)return true;
  return rightClose ? val <= to : val < to;
}

auto main() -> int {
  uint64_t profit{};
  
  std::cin >> profit;
  
  std::vector<RuleAction> ruleActions = {
    MakeRuleAction(InRange(val, 0, 10, true), CalcExtra(val, 0, 0.1)),
    MakeRuleAction(InRange(val, 10, 20), CalcExtra(val, 10, 0.075) + MatchAndApplyRule(10, ruleActions)),
    MakeRuleAction(InRange(val, 20, 40), CalcExtra(val, 20, 0.05) + MatchAndApplyRule(20, ruleActions)),
    MakeRuleAction(InRange(val, 40, 60), CalcExtra(val, 40, 0.03) + MatchAndApplyRule(40, ruleActions)),
    MakeRuleAction(InRange(val, 60, 100), CalcExtra(val, 60, 0.015) + MatchAndApplyRule(60, ruleActions)),
    MakeRuleAction(InRange(val, 100, 0, false, true, true),
                   CalcExtra(val, 100, 0.01) + MatchAndApplyRule(100, ruleActions))
  };
  
  std::cout << std::fixed << std::setprecision(6) << MatchAndApplyRule(profit, ruleActions) << std::endl;
  return EXIT_SUCCESS;
}