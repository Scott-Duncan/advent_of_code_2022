#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int findTotal(const std::vector<int> &elf){
  auto total{0};
  for (int i=0; i < elf.size(); i ++){
    total += elf.at(i);
  }

  return total;
  
}

std::vector<int> checkTopThree(const int elf, std::vector<int> top_three_elfs){
  
  if (elf > top_three_elfs.at(0)){
    top_three_elfs.at(2) = top_three_elfs.at(1);
    top_three_elfs.at(1) = top_three_elfs.at(0);
    top_three_elfs.at(0) = elf;
  } else if( elf > top_three_elfs.at(1)){
    top_three_elfs.at(2) = top_three_elfs.at(1);
    top_three_elfs.at(1) = elf;
  } else if(elf > top_three_elfs.at(2)) {
    top_three_elfs.at(2) = elf;
  } 
  return top_three_elfs;
}

int main(int argc, char * argv[])
{
    std::fstream myfile("input.txt", std::ios_base::in);

    int input;
    std::vector<int> elf;
    std::vector<int> top_three_elfs{0, 0, 0};

    string s;
    while (getline(myfile, s))
    {
        if (s.empty())
        {
          auto calories = findTotal(elf);
          top_three_elfs = checkTopThree(calories, top_three_elfs);
          elf.clear();
        }
        else
        {
            istringstream tmp(s);
            int n;
            tmp >> n;
            elf.push_back(n);
        }
    }
    
    auto top_three_cals{0};
    for (int i = 0; i < 3; i++){
      top_three_cals += top_three_elfs.at(i); 
    }

    
    printf("Calories: %i\n", top_three_cals);

    return 0;
}
