#include "../include/challenge.hpp"

RucksackInspector::RucksackInspector(const std::string &input_file){
  std::fstream myfile(input_file, std::ios_base::in);
  int total{0};

  std::string line;
  while (getline(myfile, line)) {
    if(line.empty()){break;}
    std::string rucksack_1{line.substr(0,(line.size()/2))};
    std::string rucksack_2{line.substr(((line.size()/2)), line.size())};
    std::cout << rucksack_1.size() << " : " << rucksack_2.size() << std::endl;
    total += inspectRucksack(rucksack_1, rucksack_2);
  }

  std::cout << total << std::endl;
}

int RucksackInspector::inspectRucksack(const std::string &rucksack_1, const std::string &rucksack_2){
  int total{0};
  std::string found_already{""};
  for (int i = 0; i < rucksack_1.size(); i ++){
    if(rucksack_2.find(rucksack_1[i]) != std::string::npos && found_already.find(rucksack_1[i]) == std::string::npos  ){
      total += getItemValue(rucksack_1[i]);
      found_already += rucksack_1[i];
      std::cout << found_already << std::endl;
    }
  }
  
  return total;
}

int RucksackInspector::getItemValue(const char item){
  int value = int(item);

  if(value > 96){
    return value -96;
  }else {
    return value -38;
  }

 return 0; 
}

int main(int argc, char *argv[]) {

  RucksackInspector rucksack_inspector{"config/input.txt"};

  return 0;
}
