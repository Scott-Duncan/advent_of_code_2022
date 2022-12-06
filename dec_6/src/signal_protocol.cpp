#include "../include/signal_protocol.hpp"

SignalProtocol::SignalProtocol(const std::string &file_location,
                               const int signal_length) {
  std::fstream myfile(file_location, std::ios_base::in);
  std::string line;
  while (getline(myfile, line)) {
    if (line.empty()) {
      break;
    }
    std::cout << getSignalStart(line, signal_length) << std::endl;
  }
  myfile.close();
}

int SignalProtocol::getSignalStart(const std::string &line,
                                   const int signal_length) {

  for (int i = 0; i < (line.size() - signal_length); i++) {
    bool unique{true};
    for (int j = 0; j < signal_length; j++) {
        std::cout << "Looking for: " << line[i + j] << " in: "
                  << line.substr(i + (1 * (j + 1)),
                                 signal_length - (1 * (j + 1))) << std::endl;
      if (line.substr(i + (1 * (j + 1)), signal_length - (1 * (j + 1)))
              .find(line[i + j]) != std::string::npos) {

        std::cout << "Not Unique " << std::endl;
        unique = false;
        break;
      }
    }
    if (unique) {
      return i + signal_length;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {

  SignalProtocol signal_protocol{"config/test.txt", 4};

  return 0;
}
