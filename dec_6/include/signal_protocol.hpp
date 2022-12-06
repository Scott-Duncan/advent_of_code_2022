#ifndef SIGNAL_PROTOCOL_HPP
#define SIGNAL_PROTOCOL_HPP

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class SignalProtocol {
public:
  SignalProtocol(const std::string &file_location, const int signal_length);

private:
  int getSignalStart(const std::string &line, const int signal_length);
};

#endif //! SIGNAL_PROTOCOL_HPP
