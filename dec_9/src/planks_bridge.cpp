#include "../include/planks_bridge.hpp"

BridgeCrosser::BridgeCrosser() {
  unique_points[std::tuple<int, int>{0, 0}] = 1;
}

void BridgeCrosser::moveHead(const MovePoisition direction) {
  float root5 = std::sqrt(5);
  Coordinate buffercoord = head;
  switch (direction) {
  case kUp: {
    head.y++;
    if (getHypotenuse(head, tail) == root5) {
      moveTail(buffercoord);
    } else if ((head.y - tail.y > 1)) {
      moveTail(Coordinate{tail.x, (tail.y + 1)});
    }
    return;
  }
  case kLeft: {
    head.x--;
    if (getHypotenuse(head, tail) == root5) {
      moveTail(buffercoord);
    } else if ((tail.x - head.x > 1)) {
      moveTail(Coordinate{(tail.x - 1), tail.y});
    }
    return;
  }
  case kRight: {
    head.x++;
    if (getHypotenuse(head, tail) == root5) {
      moveTail(buffercoord);
    } else if ((head.x - tail.x > 1)) {
      moveTail(Coordinate{(tail.x + 1), tail.y});
    }
    return;
  }
  case kDown: {
    head.y--;
    if (getHypotenuse(head, tail) == root5) {
      moveTail(buffercoord);
    } else if ((tail.y - head.y > 1)) {
      moveTail(Coordinate{tail.x, (tail.y-1)});
    }
    return;
  }
  }
}

void BridgeCrosser::moveTail(const Coordinate direction) {
  tail = direction;
  std::cout << "Moved tail to " << tail.x << "x, " << tail.y << "y."
            << std::endl;

  if (unique_points[std::tuple<int, int>{tail.x, tail.y}] != 1) {
    unique_points[std::tuple<int, int>{tail.x, tail.y}] = 1;
  }
}

float BridgeCrosser::getHypotenuse(const Coordinate head,
                                   const Coordinate tail) {
  int a_s = (head.x - tail.x) * (head.x - tail.x);
  int b_s = (head.y - tail.y) * (head.y - tail.y);

  std::cout << "A square : " << a_s << " B square : " << b_s << std::endl;

  float hyp = std::sqrt(a_s + b_s);
  std::cout << "Hyp : " << hyp << std::endl;

  return hyp;
}

int BridgeCrosser::getUnniquePositions() {
  int unique{0};

  for (auto const &point : unique_points) {
    unique++;
  }

  return unique;
}

int main(int argc, char *argv[]) {
  std::ifstream input(argv[1]);
  std::string line;
  BridgeCrosser bridge_crosser;
  int counter{0};

  while (getline(input, line)) {
    if (line[0] == 'U') {
      for (int i = 0; i < std::stoi(line.substr(2)); i++) {
        bridge_crosser.moveHead(kUp);
      }
    } else if (line[0] == 'D') {
      for (int i = 0; i < std::stoi(line.substr(2)); i++) {
        bridge_crosser.moveHead(kDown);
      }
    } else if (line[0] == 'L') {
      for (int i = 0; i < std::stoi(line.substr(2)); i++) {
        bridge_crosser.moveHead(kLeft);
      }
    } else if (line[0] == 'R') {
      for (int i = 0; i < std::stoi(line.substr(2)); i++) {
        bridge_crosser.moveHead(kRight);
      }
    }
  }

  int total_unique = bridge_crosser.getUnniquePositions();

  std::cout << total_unique << std::endl;

  return 0;
}
