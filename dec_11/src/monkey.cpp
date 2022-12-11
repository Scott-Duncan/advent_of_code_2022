#include "../include/monkey.hpp"
#include <cmath>

Monkey::Monkey() {}
Monkey::Monkey(const int &monkey_pass, const int &monkey_fail,
               const int &mod_check)
    : monkey_pass_(monkey_pass), monkey_fail_(monkey_fail),
      mod_check_(mod_check) {}

ThrownItem Monkey::throwItem() {
  ThrownItem thrown;
  int item = items_.front();
  items_.pop();
  item = carryOutWorry(item);
  thrown.monkey = checkTest(item);
  thrown.value = item;
  return thrown;
}

int Monkey::carryOutWorry(const int &worry) {
  num_of_check_++;
  float stress{0.f};
  float new_worry;
  if (new_ == 0) {
    stress = float(worry);
  } else {
    stress = float(new_);
  }

  switch (operation_) {
  case kMultiply: {
    std::cout << "Worry: " << int(std::floor((stress * worry)/3));
    return int(std::floor((stress * worry)/3));
  }
  case kAdd: {
    std::cout << "Worry: " << int(std::floor((stress + worry)/3));
    return int(std::floor((stress + worry)/3));
  }
  }
  return 0;
}

int Monkey::checkTest(const int &check_item) {
  if (check_item % mod_check_ == 0) {
    std::cout << ". Passed, sending to " << monkey_pass_ << std::endl;
    return monkey_pass_;
  } else {
    std::cout << ". Failed, sending to " << monkey_fail_ << std::endl;
    return monkey_fail_;
  }
}
