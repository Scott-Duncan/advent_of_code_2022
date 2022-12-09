#ifndef PLANKS_BRIGDE_HPP
#define PLANKS_BRIGDE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <cmath>
#include <stdlib.h>
#include <tuple>

struct Coordinate {
  int x;
  int y;
};

enum MovePoisition { kUp, kRight, kLeft, kDown };

class BridgeCrosser {
public:
  BridgeCrosser();

  void moveHead(const MovePoisition direction);

  void moveTail(const Coordinate direction);

  int getUnniquePositions();

private:

  float getHypotenuse(const Coordinate head, const Coordinate tail);

  Coordinate head{0,0};
  Coordinate tail{0,0};

  std::map<std::tuple<int, int>, int> unique_points;
};

#endif //! PLANKS_BRIGDE_HPP
