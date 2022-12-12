#include "map.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>

int main (int argc, char *argv[])
{
  std::fstream input(argv[1]);
  std::string line;
  std::vector<std::vector<int>> map;
  int start;
  int end;
  auto counter{0};
  std::vector<int> starts;

  while (getline(input,line)){
    map.push_back(std::vector<int>(line.size()));
    for (int i = 0 ; i < line.size() ; i ++){
      if (line [i] == 'S'){
        map.at(counter).at(i) = 0;
        start = (counter*line.size() + i);
        continue;
      } else if (line[i] == 'E') {
        end = (counter*line.size() + i);
        map.at(counter).at(i) = int('z'-'a');
        continue;
      }
      if(line[i] == 'a'){
        starts.push_back(counter*line.size() + i);
      }
      map.at(counter).at(i) = int(line[i] - 'a');
    }
    counter ++;
  }

  std::cout << "Start: " << start << std::endl;
  std::cout << "End: " << end << std::endl;

  ElfMap elf_map(map.at(0).size(), map.size());
  elf_map.drawMap(map);
  auto min{1000};
  for (const auto& strt: starts){
    auto path = elf_map.bestRoute(strt,end);
    if (path < min){
      min = path;
    }
  }

  std::cout << "Best path is " << min << std::endl;
  return 0;
} 
