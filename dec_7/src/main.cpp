#include "directory.cpp"
#include <fstream>
#include <sstream>

int getFileSize(const std::string &line) {
  std::istringstream tmp(line);
  int size;

  tmp >> size;

  return size;
}

int main(int argc, char *argv[]) {
  std::fstream myfile(argv[1], std::ios_base::in);
  std::string line;

  std::shared_ptr<Directory> directory = std::make_shared<Directory>(Directory("/", NULL));

  getline(myfile, line);
  getline(myfile, line);

  while (getline(myfile, line)) {
    if (line.empty()) {
      break;
    }
    if (line.substr(0, 3) == "dir") {
      directory->addDirectory(line.substr(4),
                              (std::make_shared<Directory>(line.substr(4), directory)));
    } else if (line.substr(2, 2) == "cd") {
      if (line.substr(5) == "..") {
        if (directory->getParent() != NULL) {
          directory = directory->getParent();
        }
      }else  if (directory->getDirectories().find(line.substr(5)) !=
          directory->getDirectories().end()) {
        directory = directory->getDirectories()[line.substr(5)];
      }
    } else {
      directory->setSize(getFileSize(line));
    }
  }

  while (directory->getParent() != NULL) {
    directory = directory->getParent();
  }

  std::cout << directory->getSize() << std::endl;

  return 0;
}
