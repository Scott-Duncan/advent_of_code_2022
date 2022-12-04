#include "../include/challenge.hpp"

RucksackInspector::RucksackInspector(const std::string &input_file){
  std::fstream myfile(input_file, std::ios_base::in);
  int total{0};
  int counter{0};
  std::vector<std::string> elfs;

  std::string line;
  while (getline(myfile, line)) {
    std::cout << "Counter: " << counter << std::endl;
    if(line.empty()){break;}
    if (counter < 2){
      elfs.push_back(line);
      counter ++;
    } else {
      elfs.push_back(line);
      total += inspectElfGroup(elfs);
      elfs.clear();
      counter = 0;
    }
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

int RucksackInspector::inspectElfGroup(const std::vector<std::string> &elfs){
  int total{0};
  std::string found_already{""};
  for (int i = 0; i < elfs.at(0).size(); i ++){
    if(elfs.at(1).find(elfs.at(0)[i]) != std::string::npos && elfs.at(2).find(elfs.at(0)[i]) != std::string::npos && found_already.find(elfs.at(0)[i]) == std::string::npos  ){
      return getItemValue(elfs.at(0)[i]);
      // found_already += elfs.at(0)[i];
      // std::cout << found_already << std::endl;
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
