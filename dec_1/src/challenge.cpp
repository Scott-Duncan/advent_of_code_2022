#include "../include/challenge.hpp"

ElfCalorieCounter::ElfCalorieCounter(const std::string &file_location) {
  file_location_ = file_location;
}

int ElfCalorieCounter::FindTopThree() {
  std::fstream myfile(file_location_, std::ios_base::in);

  std::vector<int> elf;
  std::vector<int> top_three_elfs{0, 0, 0};

  std::string line;
  while (getline(myfile, line)) {
    int input;
    if (line.empty()) {
      auto calories =
          std::accumulate(elf.begin(), elf.end(), decltype(elf)::value_type(0));
      top_three_elfs = checkTopThree(calories, top_three_elfs);
      elf.clear();
    } else {
      int calories;
      std::istringstream tmp(line);
      tmp >> calories;
      elf.push_back(calories);
    }
  }
  myfile.close();

  auto top_three_cals{0};
  for (auto &elf : top_three_elfs) {
    top_three_cals += elf;
  }

  return top_three_cals;
}

ElfCalorieCounter::TopElf ElfCalorieCounter::findTopElf() {
  std::fstream myfile(file_location_, std::ios_base::in);

  int elf_calories;
  int counter{0};
  TopElf top_elf{0, 0};

  std::string line;
  while (getline(myfile, line)) {
    int input;
    if (line.empty()) {
      if (top_elf.calories < elf_calories) {
        top_elf.calories = elf_calories;
        top_elf.position = counter;
      }
      elf_calories = 0;
      counter++;
    } else {
      int calories;
      std::istringstream tmp(line);
      tmp >> calories;
      elf_calories += calories;
    }
  }

  myfile.close();
  return top_elf;
}

std::vector<int>
ElfCalorieCounter::checkTopThree(const int elf,
                                 std::vector<int> top_three_elfs) {
  if (elf > top_three_elfs.at(0)) {
    top_three_elfs.at(2) = top_three_elfs.at(1);
    top_three_elfs.at(1) = top_three_elfs.at(0);
    top_three_elfs.at(0) = elf;
  } else if (elf > top_three_elfs.at(1)) {
    top_three_elfs.at(2) = top_three_elfs.at(1);
    top_three_elfs.at(1) = elf;
  } else if (elf > top_three_elfs.at(2)) {
    top_three_elfs.at(2) = elf;
  }
  return top_three_elfs;
}

int main(int argc, char *argv[]) {

  ElfCalorieCounter elf_counter{"../config/input.txt"};
  auto top_three_elf_sum = elf_counter.FindTopThree();
  auto top_elf = elf_counter.findTopElf();

  printf("Top Elf %i, ate %i calories.", top_elf.position, top_elf.calories);
  printf("Top three elves ate %i calories", top_three_elf_sum);

  return 0;
}
