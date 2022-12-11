#include "../include/screen.hpp"
#include <iostream>

Screen::Screen(const std::string &input_file) {
  std::ifstream input(input_file);
  std::string line;
  int cycle{0};

  std::cout << "#";
  while (getline(input, line)) {
    if (line.empty()) {
      break;
    }
    cycle++;

    if (line[0] == 'n') {
      checkCycle(cycle);
      continue;
    } else {
      checkCycle(cycle);
      cycle++;
      int change = std::stoi(line.substr(5));
      x_ += change;
      checkCycle(cycle);
    }
  }

  std::cout << signal_strength_ << std::endl;
}

void Screen::checkCycle(const int &cycle) {
  if (cycle % 40 == 0) {
    std::cout << std::endl;
  }
  if((cycle%40) == x_ - 1){
    std::cout << "#"; 
  } else if((cycle%40) == x_){
    std::cout << "#"; 
  } else if((cycle%40) == x_ + 1){
    std::cout << "#"; 
  } else {
    std::cout << ".";

  }
}

int main(int argc, char *argv[]) {
  Screen screen(argv[1]);
  return 0;
}
