#include "../include/map.hpp"
#include <algorithm>
#include <iostream>

ElfMap::ElfMap(const size_t &width, const size_t height)
    : width_(width), height_(height) {}

int ElfMap::bestRoute(const int &start, const int &end) {
  // Mark all the vertices as not visited
  int size{int(adj_.size())};
  std::vector<int> paths;
  for (const auto &node : adj_.at(start)) {
    // std::cout << "Starting at node: " << node << std::endl;
    std::vector<int> d(size), p(size);
    std::vector<bool> visited(size, false);
    // Create a queue for BFS
    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[node] = true;
    queue.push_back(node);
    p[node] = -1;

    while (!queue.empty()) {
      // Dequeue a vertex from queue and print it
      int s = queue.front();
      // std::cout << s << " ";
      queue.pop_front();

      // Ge all adjacent vertices of the dequeued
      // vertex s. If a adjacent has not been visited,
      // then mark it visited and enqueue it
      for (auto adjecent : adj_[s]) {
        if (!visited[adjecent]) {
          // std::cout << adjecent << ", ";
          visited[adjecent] = true;
          queue.push_back(adjecent);
          d[adjecent] += d[s] + 1;
          p[adjecent] += s;
        }
      }
    }
    if (!visited[end]) {
    } else {
      std::vector<int> path;
      for (int v = end; v != -1; v = p[v]) {
        path.push_back(v);
      }
      reverse(path.begin(), path.end());
      int ccount{0};
      for (int v : path) {
        ccount++;
        // std::cout << v << " ";
      }
      paths.push_back(ccount);
    }
  }
  auto min{10000};
  for (const auto & path : paths){
    if (min > path){
      min = path;
    }
  }
  
  return min;
}

void ElfMap::drawMap(const std::vector<std::vector<int>> &map) {
  int mult = map.at(0).size();
  adj_.resize(map.size() * map.at(0).size());
  for (int x = 0; x < map.size(); x++) {
    for (int y = 0; y < map.at(x).size(); y++) {
      if (x - 1 >= 0) {
        if (( map.at(x - 1).at(y) -map.at(x).at(y) ) <= 1) {
          adj_.at((x * mult) + y).push_back(((x - 1) * mult + y));
        }
      }
      if (y - 1 >= 0) {
        if (map.at(x).at(y - 1)- (map.at(x).at(y)) <= 1) {
          adj_.at((x * mult) + y).push_back(((x)*mult + y - 1));
        }
      }
      if (x + 1 < map.size() && y + 1 < mult) {
        if (( map.at(x + 1).at(y) - map.at(x).at(y)) <= 1) {
          adj_.at((x * mult) + y).push_back(((x + 1) * mult + y));
        }
      }
      if (y + 1 < mult) {
        if (( map.at(x).at(y + 1) -map.at(x).at(y)) <= 1) {
          adj_.at((x * mult) + y).push_back(((x)*mult + y + 1));
        }
      }
    }
  }
}
