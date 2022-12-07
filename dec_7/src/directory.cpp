#include "../include/directory.hpp"
#include <iostream>

int Directory::getSize() {
  int size{size_};

  for(auto const  &directory: directories_){
    size += directory.second->getSize();
  }

  if(size >= 5349983){
    std::cout << name_ << " size: " << size << std::endl; 
  }  
  return size;
}

int Directory::getTestSize() {
  int size{test_size};

  for(auto const  &directory: directories_){
    size += directory.second->getTestSize();
  }

  return size;
  
}
