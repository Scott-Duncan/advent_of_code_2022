#ifndef MONKEY_HPP
#define MONKEY_HPP

#include <queue>
#include <string>
#include <iostream>

struct ThrownItem {
  int value;
  int monkey;
};

enum Operation {
  kMultiply,
  kAdd,
};

class Monkey {
public:
  Monkey();
  Monkey(const int &monkey_pass, const int &monkey_fail, const int &mod_check);

  inline int getQueueSize() { return int(items_.size()); }

  inline int getNumberOfCheck() { return int(num_of_check_); }

  inline void addItem(const int &item) { items_.push(item); }

  inline void setOp(const Operation op){ operation_ = op;}

  inline void setDiff(const int &diff){new_ = diff;}

  ThrownItem throwItem();

  void printItems(){ for (int i = 0; i < items_.size(); i ++){
    int item = items_.front();
    items_.pop();
    items_.push(item);
    std::cout << " " << item;}
  }

private:
  size_t carryOutWorry(const size_t &worry);

  int checkTest(const int &check_item);

  Operation operation_;

  int monkey_pass_;

  int monkey_fail_;

  int mod_check_;

  int new_{0};

  int num_of_check_{0};

  std::queue<size_t> items_;
};

#endif //! MONKEY_HPP
