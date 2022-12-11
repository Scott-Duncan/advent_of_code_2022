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

size_t Monkey::carryOutWorry(const size_t &worry) {
  num_of_check_++;
  size_t stress{0};
  size_t new_worry;
  size_t mod = 13 * 7 * 2 * 17 * 5 * 11 * 3 * 19; 
  if (new_ == 0) {
    stress = worry;
  } else {
    stress = new_;
  }

  switch (operation_) {
  case kMultiply: {
    return (size_t(stress * worry) % mod);
  }
  case kAdd: {
    return (size_t(stress + worry) % mod);
  }
  }
  return 0;
}

int Monkey::checkTest(const int &check_item) {
  if (check_item % mod_check_ == 0) {
    return monkey_pass_;
  } else {
    return monkey_fail_;
  }
}
