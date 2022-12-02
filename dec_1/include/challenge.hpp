#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <functional>

class ElfCalorieCounter {
public:
  struct TopElf {
    int position;
    int calories;
  };

  ElfCalorieCounter(const std::string &file_location);

  int FindTopThree();

  TopElf findTopElf();

private:
  std::vector<int> checkTopThree(const int elf,
                                 std::vector<int> top_three_elves);

  std::string file_location_;
};

#endif //! CHALLENGE_H
