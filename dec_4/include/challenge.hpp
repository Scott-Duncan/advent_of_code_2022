#ifndef CHALLENGE_HPP
#define CHALLENGE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <functional>

class CleaningPairs {
public:
  CleaningPairs(const std::string &file_location);

  std::vector<int> getRows(const std::string &line);

private:

  bool checkIfRowsMatch(const std::vector<int> &rows);

  int getInt(const std::string &row);
  
};

#endif //! CHALLENGE_HPP
