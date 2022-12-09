#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <set>
#include <string>
#include <math.h>


class Snake {
struct Coordinate {
  int x{0};
  int y{0};
};
 public: 
  Snake(const size_t &size_of_snake);

  void followHead(Coordinate &knot, const Coordinate &head);

  void moveHead(const int x, const int &y); 
 
 private: 
  bool getHypotenuse(const Coordinate & a, const Coordinate & b);

  std::vector<Coordinate> snake_knots_;

  std::set<std::string> visited_coords_;

  size_t size_of_snake_;
};

#define //! SNAKE_HPP
