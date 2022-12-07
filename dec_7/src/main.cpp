#include "../include/directory.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

size_t getFileSize(const std::string &line) {
  std::istringstream tmp(line);
  size_t size;

  tmp >> size;

  return size;
}

int main(int argc, char *argv[]) {
  std::fstream myfile(argv[1], std::ios_base::in);
  std::string line;

  Directory* directory =
      (new Directory("/", NULL));
  std::cout << directory->getName() << std::endl;

  getline(myfile, line);
  getline(myfile, line);

  while (getline(myfile, line)) {
    if(line.empty()){break;}
    std::cout << directory->getName() << ", size : " << directory->size_ << std::endl;
    std::cout << line << std::endl;
    if (line.substr(0, 3) == "dir") {
      directory->addDirectory(
          line.substr(4),
          (new Directory(line.substr(4), directory)));
    } else if (line.substr(2, 2) == "cd") {
      if (line.substr(5) == ".."){
        if (directory->getParent() != NULL){
          std::cout << "Parent : " << directory->getParent()->getName() << std::endl;
          directory = directory->getParent();
        }
      }
      if (directory->getDirectories().find(line.substr(5)) !=
          directory->getDirectories().end()) {
        directory = directory->getDirectories()[line.substr(5)];
      }
    } else {
      directory->setSize(getFileSize(line));
      // std::cout << getFileSize(line) << std::endl;
    }
  }

  while (directory->getParent() != NULL) {
    directory = directory->getParent();
  }

  std::cout << directory->getName();

  return 0;
}
