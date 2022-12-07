#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <map>
#include <memory>
#include <stdlib.h>

class Directory {
public:
  Directory(const std::string &name, std::shared_ptr<Directory> parent)
      : name_{name}, parent_{parent} {};

  void addDirectory(const std::string &name,
                    std::shared_ptr<Directory> directory) {
    directories_[name] = directory;
  }

  size_t getSize();

  void setSize(const size_t &size) { size_ += size; }

  inline std::string getName() { return name_; }

  inline std::map<std::string, std::shared_ptr<Directory>> getDirectories() {
    return directories_;
  }

  inline std::shared_ptr<Directory> getParent() { return parent_; }

  size_t size_{0};
private:

  std::string name_;

  Directory* parent_;

  std::map<std::string, std::shared_ptr<Directory>> directories_;
};

#endif //! DIRECTORY_HPP
