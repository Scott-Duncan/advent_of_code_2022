#include "monkey.cpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>
#include <vector>

void addListItems(const std::string &list,Monkey &monkey){
  for (int i =0; i < list.size() ; i +=4){
    monkey.addItem(std::stoi(list.substr(i,2)));
  }
}

void setModifiers(const std::string mods, Monkey &monkey){
  std::string bin;
  std::istringstream temp(mods);
  temp >> bin;
  temp >> bin;
  temp >> bin;
  temp >> bin;
  if (bin [0] == '*'){
    monkey.setOp(kMultiply);
  } else {
    monkey.setOp(kAdd);
  }
  temp >> bin;
  if (bin[0] != 'o'){
    monkey.setDiff(std::stoi(bin)); 
  }
}

int getTest(const std::string &test){
  std::string bin;
  std::istringstream temp(test);
  temp >> bin;
  temp >> bin;
  temp >> bin;
  return std::stoi(bin);

}

Monkey parseMonkey(const YAML::Node &node){
  int test = getTest(node["Test"].as<std::string>());
  int pass = std::stoi(node["If true"].as<std::string>().substr(node["If true"].as<std::string>().size()-1));
  int fail = std::stoi(node["If false"].as<std::string>().substr(node["If false"].as<std::string>().size()-1));
  Monkey monkey(pass, fail, test);
  addListItems(node["Starting items"].as<std::string>(), monkey);
  setModifiers(node["Operation"].as<std::string>(),monkey);
 
  return monkey;
}

int main (int argc, char *argv[])
{
  const auto input = YAML::LoadFile(argv[1]); 
  std::vector<Monkey> monkies;
  monkies.resize(input.size());
  auto count{0};

  for (const auto& node : input) {
    std::string monkey_name= node.first.as<std::string>();
    int monkey_num = std::stoi(monkey_name.substr(monkey_name.size()-2)); 
    monkies.at(monkey_num) =  parseMonkey(node.second);
  }

  for (int i =0 ; i < 10000; i ++){
    for(int j = 0; j < monkies.size() ; j ++){
      auto q_size = monkies.at(j).getQueueSize();
      for(int k = 0; k < q_size; k ++){
        ThrownItem thrown = monkies.at(j).throwItem(); 
        monkies.at(thrown.monkey).addItem(thrown.value);
      }
    }
  }

  for (int i = 0; i < monkies.size(); i ++) {
    std::cout << "Monkey " << i << " " << monkies.at(i).getNumberOfCheck() << std::endl;
  }

  return 0;

}
