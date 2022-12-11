#include "../include/screen.hpp"
#include <iostream>

Screen::Screen (const std::string &input_file){
  std::ifstream input(input_file); 
  std::string line;
  int cycle{0};

  while (getline(input, line)){
    if(line.empty()){break;} 
    cycle ++;
    std::cout << "Cycle : " << cycle << std::endl;

    if (line[0] == 'n') {
      checkCycle(cycle);
      continue; 
    } else {
      std::cout << "Command: " << line << std::endl;
      checkCycle(cycle);
      cycle ++;
      checkCycle(cycle);
      std::cout << "Cycle : " << cycle << std::endl;
      int change = std::stoi(line.substr(5));
      std::cout << "Change: " << change << std::endl;
      x_ += change;
    }
  }

  std::cout << signal_strength_ << std::endl;
}

void Screen::checkCycle(const int &cycle) {
    if((cycle +20)% 40 == 0){
      signal_strength_ += x_*cycle; 
      std::cout << "X is currently : " << x_ << " cycle is " << cycle <<  std::endl;
      std::cout << "Signal strength: " << x_*cycle << std::endl;
    }

}
 
int main (int argc, char *argv[])
{
  Screen screen(argv[1]); 
  return 0;
}
