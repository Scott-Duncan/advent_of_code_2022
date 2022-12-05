#include "../include/crane.hpp"
#include <bits/stdc++.h>

Crane::Crane(const std::string &file_location, const int columns) {
  std::fstream myfile(file_location, std::ios_base::in);
  std::string line;

  stack.resize(9);

  for (int i = 0; i < 8; i++) {
    getline(myfile, line);
    populateStack(line, columns, myfile);
  }
  for (int z = 0; z < 9; z++) {
    reverse(stack.at(z).begin(), stack.at(z).end());
  }

  getline(myfile, line);
  getline(myfile, line);

  while (getline(myfile, line)) {
    std::vector<int> instructions = getMoves(line);
    useCrane(instructions.at(1), instructions.at(2), instructions.at(0));
  }

  for (int z = 0; z < 9; z++) {
    std::cout << stack.at(z).at(stack.at(z).size()-1);
    std::cout << std::endl;
  }
}

std::vector<int> Crane::getMoves(const std::string &row) {
  std::vector<int> moves;
  int move;
  std::string bin;
  std::istringstream tmp(row);
  for (int i = 0; i < 3; i++) {
    tmp >> bin;
    tmp >> move;
    moves.push_back(move);
  }

  return moves;
}

void Crane::populateStack(const std::string &row, const int columns,
                          std::fstream &file) {

  for (int j = 0; j < columns; j++) {
    char temp = (row.substr((4 * j), 3)[1]);
    if (temp != ' ') {
      stack.at(j).push_back(temp);
    }
  }
}

void Crane::useCrane(const int start_col, const int end_col,
                     int number_of_moves) {
  for (int i = 0; i < number_of_moves; i++) {
    if (stack.at(start_col - 1).size() != 0) {
      auto size = stack.at(start_col - 1).size();
      stack.at(end_col - 1).push_back(stack.at(start_col - 1).at(size - 1));
      stack.at(start_col - 1).pop_back();
      stack.at(start_col - 1).shrink_to_fit();
      std::cout << "Size of " << start_col - 1 << size -1 << std::endl;
    }else {
      std::cout << "empty" << std::endl;
      break;
    }
  }
}

int main(int argc, char *argv[]) {

  Crane crane{"config/input.txt", 9};

  return 0;
}
