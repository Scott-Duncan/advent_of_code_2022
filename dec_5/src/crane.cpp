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
    if (line.empty()) {
      break;
    }
    std::vector<int> instructions = getMoves(line);
    useCrane(instructions.at(1), instructions.at(2), instructions.at(0));
  }

  for (int z = 0; z < 9; z++) {
    if (stack.at(z).size() != 0) {
      std::cout << stack.at(z).at(stack.at(z).size() - 1);
    }
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
  auto moves{0};
  std::cout << "Start col size: " << stack.at(start_col - 1).size()
            << ", End col size: " << stack.at(end_col - 1).size()
            << " number of moves: " << number_of_moves << std::endl;
  int start = (int(stack.at(start_col - 1).size()) - number_of_moves);
  std::cout << start << std::endl;
  for (int i = start; i < int(stack.at(start_col - 1).size()); i++) {
    std::cout << i;
    if (i >= 0 && i < int(stack.at(start_col - 1).size())) {
      stack.at(end_col - 1).push_back(stack.at(start_col - 1).at(i));
      moves++;
    }
  }
  std::cout << std::endl;
  for (int j = 0; j < moves; j++) {
    if (stack.at(start_col - 1).size() > 0) {
      stack.at(start_col - 1).pop_back();
      stack.at(start_col - 1).shrink_to_fit();
    }
  }
}

int main(int argc, char *argv[]) {

  Crane crane{"config/input.txt", 9};

  return 0;
}
