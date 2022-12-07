#include "../include/directory.hpp"

size_t Directory::getSize() {
  size_t size{size_};

  for(auto const  &directory: directories_){
    size += directory.second->getSize();
  }

  return size;
}
