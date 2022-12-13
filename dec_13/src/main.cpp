#include <string>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>

bool is_number (const char c) {
  return c >= '0' && c <= '9';
}

bool compare (const std::string& packet1, const std::string& packet2) {
  int i1 = 0;
  int i2 = 0;
  while (i1 < packet1.size() && i2 < packet2.size()) {
    if (is_number(packet1[i1]) && is_number(packet2[i2])) {
      int n1 = 0;
      while (is_number(packet1[i1])) {
        n1 = n1 * 10 + (packet1[i1] - '0');
        i1++;
      }
      int n2 = 0;
      while (is_number(packet2[i2])) {
        n2 = n2 * 10 + (packet2[i2] - '0');
        i2++;
      }
      if (n1 == n2) {
        continue;
      }
      if (n1 < n2) {
        return true;
      }
      break;
    } else if (packet1[i1] == packet2[i2]) {
      i1++;
      i2++;
    } else if (packet1[i1] == ']') {
      return true;
    } else if (packet2[i2] == ']') {
      break;
    } else if (packet1[i1] == '[' || packet1[i1] == ',') {
      i1++;
    } else if (packet2[i2] == ',' || packet2[i2] == '[') {
      i2++;
    }
  }
  if (i1 == packet1.size()) {
    return true;
  }
  return false;
}

int main(int argc, char * argv[]) {
  std::string input;
  if (argc > 1) {
    input = argv[1];
  }

  std::string packet1, packet2;
  std::fstream file(input);

  int index = 0;
  int sum = 0;

  while(std::getline(file, packet1)) {
    if (packet1.empty()) continue;
    std::getline(file, packet2);
    index++;
    if (compare(packet1, packet2)) {
      sum += index;
    }
  }

  std::cout << sum << '\n';
  return 0;
}
