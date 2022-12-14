#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void debugPrint(const std::vector<std::vector<int>> &debug){
  //print block
  std::cout << "--------------" << std::endl;
  for (int i = 0 ; i < 10 ; i ++){
    for (int j = 493 ; j < 504 ; j ++){
      std::cout << debug.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}

std::vector<std::string> splitString(const std::string &line,
                                     const std::string &delim) {
  auto pos{0};
  auto current_string = line;
  std::vector<std::string> split;

  pos = current_string.find(delim);
  if (pos == std::string::npos) {
    split.push_back(current_string);
    return split;
  }
  while (pos != std::string::npos) {
    split.push_back(current_string.substr(0, pos));
    current_string = current_string.substr(pos + delim.size());
    pos = current_string.find(delim);
  }
  split.push_back(current_string);

  return split;
}

std::vector<std::vector<int>> getInstructions(const std::string &line) {
  std::vector<std::vector<int>> instructions;
  std::vector<std::string> stringstructions = splitString(line, "->");

  for (const auto &instruction : stringstructions) {
    std::vector<int> set;
    std::istringstream temp(instruction.substr(0, instruction.find(',')));
    int value;
    temp >> value;
    std::istringstream temp2(instruction.substr(instruction.find(',') + 1));
    int value2;
    temp2 >> value2;
    set.push_back(value);
    set.push_back(value2);
    instructions.push_back(set);
  }

  return instructions;
}

int main(int argc, char *argv[]) {
  std::fstream input{argv[1]};
  std::string line;
  std::vector<std::vector<int>> cave;
  auto cave_width{600};
  auto cave_depth{12};

  for (int i = 0; i < cave_depth-1; i++) {
    cave.push_back(std::vector<int>(cave_width, 0));
  }
  cave.push_back(std::vector<int>(cave_width, 1));

  while (getline(input, line)) {
    if (line.empty()) {
      break;
    }
    auto instructions = getInstructions(line);
    for (int i = 0; i < instructions.size() - 1; i ++) {
      if (instructions.at(i).at(0) == instructions.at(i + 1).at(0)) {
        auto col = instructions.at(i).at(0);
        auto start{0};
        auto end{0};
        if (instructions.at(i).at(1) < instructions.at(i + 1).at(1)) {
          start = instructions.at(i).at(1);
          end = instructions.at(i + 1).at(1);
        } else {
          end = instructions.at(i).at(1);
          start = instructions.at(i + 1).at(1);
        }
        for (int j = start; j < end+1; j++) {
          cave.at(j).at(col) = 1;
        }
      }
      if (instructions.at(i).at(1) == instructions.at(i + 1).at(1)) {
        auto row = instructions.at(i).at(1);
        auto start{0};
        auto end{0};
        if (instructions.at(i).at(0) < instructions.at(i + 1).at(0)) {
          start = instructions.at(i).at(0);
          end = instructions.at(i + 1).at(0);
        } else {
          end = instructions.at(i).at(0);
          start = instructions.at(i + 1).at(0);
        }
        for (int j = start; j < end+1; j++) {
          cave.at(row).at(j) = 1;
        }
      }
    }
  }


  // sand time
  auto abbys{false};
  auto sand_drops{0};
  while (!abbys) {
    sand_drops++;
    auto sand_col{500};
    for (int i = 0; i < cave_depth - 1; i++) {
      if (cave.at(i).at(sand_col) == 2) {
        abbys = true;
        break;
      }

      if (cave.at(i + 1).at(sand_col) == 0) {
        if ( i == cave_depth-2) {
          abbys = true;
          break;
        }
        continue;
      } else {
        if (cave.at(i + 1).at(sand_col - 1) == 0) {
          sand_col--;
        } else if (cave.at(i + 1).at(sand_col + 1) == 0) {
          sand_col++;
        } else {
            cave.at(i).at(sand_col) = 2;
            debugPrint(cave);
            break;
        }
      }
    }
  }

  std::cout << "Sandrops are : " << sand_drops << std::endl;

  return 0;
}
