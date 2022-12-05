#ifndef CRANE_HPP
#define CRANE_HPP 

#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>

class Crane {
public: 

  Crane(const std::string &file_location, const int columns);
  
private:

  void populateStack(const std::string &row, const int columns, std::fstream &file);

  void useCrane(const int start_col, const int end_col, int number_of_moves);

  std::vector<int> getMoves(const std::string &row);

  std::vector<std::vector<char>> stack;

};

#endif //! CRANE_HPP
