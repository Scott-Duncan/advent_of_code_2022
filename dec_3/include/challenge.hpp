#ifndef CHALLENGE_HPP
#define CHALLENGE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <functional>

class RucksackInspector {
public:

  RucksackInspector(const std::string &input_file);

  int inspectRucksack(const std::string &rucksack_1, const std::string &rucksack_2);

private:

  int getItemValue(const char item);

};


#endif // !CHALLENGE_HPP
