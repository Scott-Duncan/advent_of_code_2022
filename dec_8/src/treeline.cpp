#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<int> getTreeline(const std::string &line) {
  std::vector<int> treeline;
  for (int i = 0; i < line.length(); i++) {
    treeline.push_back(int(line[i]) - '0');
  }

  return treeline;
}

int amountTreeVisible(const int x, const int y,
                      const std::vector<std::vector<int>> &treelines) {
  int visibleUp{0}, visibleLeft{0}, visibleDown{0}, visibleRight{0};
  auto treeHeight = treelines.at(y).at(x);

  // Check up first
  for (int i = y - 1; i > -1; i--) {
    visibleUp++;
    if (treelines.at(i).at(x) >= treeHeight) {
      break;
    }
  }

  // Check left next
  for (int i = x - 1; i > -1; i--) {
    visibleLeft++;
    if (treelines.at(y).at(i) >= treeHeight) {
      break;
    }
  }

  // Check down next
  for (int i = y + 1; i < treelines.size(); i++) {
    visibleDown++;
    if (treelines.at(i).at(x) >= treeHeight) {
      break;
    }
  }

  // Check right last
  for (int i = x + 1; i < treelines.at(0).size(); i++) {
    visibleRight++;
    if (treelines.at(y).at(i) >= treeHeight) {
      break;
    }
  }

  int vis = (visibleRight * visibleDown * visibleUp * visibleLeft);
  return vis;
}

int main(int argc, char *argv[]) {
  std::ifstream input(argv[1]);
  std::string line;
  std::vector<std::vector<int>> treelines;

  while (getline(input, line)) {
    if (line.empty()) {
      break;
    }
    treelines.push_back(getTreeline(line));
  }

  int max{0};

  for (int y = 1; y < treelines.size() - 1; y++) {
    for (int x = 1; x < treelines.at(0).size() - 1; x++) {
      auto vis = amountTreeVisible(x, y, treelines);
      std::cout << "Amount Visible: " << vis << std::endl;
      if (vis > max) {
        max = vis;
      }
    }
  }

  std::cout << "Visible trees: " << max << std::endl;

  return 0;
}
