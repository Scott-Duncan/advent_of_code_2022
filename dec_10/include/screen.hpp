#ifndef SCREEN_HPP
#define SCREEN_HPP 

#include <string>
#include <fstream>
#include <string.h>

class Screen {
  public:
   Screen(const std::string &input_file);

   void checkCycle(const int &cycle);

private: 

  int x_{1};
  
  int signal_strength_{0};
   
};

#endif //! SCREEN_HPP
