#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> parseXY(const std::string &line) {
  std::vector<int> positions;
  std::string current_line = line;

  auto current_start = current_line.find('x');
  auto current_end = current_line.find(',') - current_start;
  positions.push_back(
      std::stoi(current_line.substr(current_start + 2, current_end - 2)));

  current_line = current_line.substr(current_end + 1);
  current_start = current_line.find('y');
  current_end = current_line.find(',') - current_start;
  positions.push_back(std::stoi(current_line.substr(current_start + 2)));

  return positions;
}

std::vector<int> parseLine(const std::string &line) {
  std::vector<int> positions;
  std::string first_line{line.substr(0, line.find(':'))};
  std::string second_line{line.substr(line.find(':') + 2)};

  auto first = parseXY(first_line);
  positions.push_back(first[0]);
  positions.push_back(first[1]);

  auto second = parseXY(second_line);
  positions.push_back(second[0]);
  positions.push_back(second[1]);

  return positions;
}

void drawExlusion(std::vector<char> map) {}

int main(int argc, char *argv[]) {
  std::ifstream input{argv[1]};
  std::string line;
  std::vector<std::vector<int>> beacons;
  std::vector<char> cave;
  auto cave_height{0};
  auto cave_width{0};

  for (int i = 0; i < cave_height; i++) {
    for (int j = 0; i < cave_width; i++) {
      cave.push_back('.');
    }
  }

  while (getline(input, line)) {
    parseLine(line);
  }

  return 0;
}
