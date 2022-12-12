#ifndef ELF_MAP_HPP
#define ELF_MAP_HPP 

#include <list>
#include <vector>


class ElfMap {
 public: 
  ElfMap(const size_t &width, const size_t height); 

  int bestRoute(const int &start, const int &end);

  void drawMap(const std::vector<std::vector<int>> &map);

  std::vector<std::list<int>> adj_;

 private: 

  size_t width_;
  size_t height_;
};

#endif //! MAP_HPP
  
