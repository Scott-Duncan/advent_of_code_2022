#include "../include/snake.hpp"

Snake::Snake(const size_t &size_of_snake): size_of_snake_(size_of_snake) {
  for (int i = 0; i < size_of_snake_; i ++){
    snake_knots_.push_back(Coordinate{0,0}); 
  }
  visited_coords_.emplace("00");
}

void Snake::followHead(Coordinate &knot, const Coordinate &head) {

  // head further right
  if (head.x - knot.x > 1) {  
    if(getHypotenuse(head, knot)){
      knot.x = head.x -1;
      knot.y = head.y;
    } else {
      knot.x ++;
    }
  // head further left
  } else if (knot.x - head.x > 1) {
    if (getHypotenuse(head,knot)){
      knot.x = head.x + 1; 
      knot.y = head.y;
    }
  // Higher
  } else if (head.y - knot.y > 1) {
    if (getHypotenuse(knot, head)){
      knot.x = head.x;
      knot.y = head.x 
    }
  }

 
}

void Snake::moveHead(const int x, const int &y){
  snake_knots_.at(0).x += x; 
  snake_knots_.at(0).x += y;
}

bool Snake::getHypotenuse(const Coordinate &a, const Coordinate & b) {
  int a_squared = (a.x - b.x) * (a.x - b.x);
  int b_squared = (a.y - b.y) * (a.y - b.y);

  return (std::sqrt(a_squared + b_squared) >= std::sqrt(5));
}
