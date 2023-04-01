#pragma once
#include <filesystem>
#include <vector>

namespace nb {
class Directory {
  using Entries = std::vector<std::filesystem::directory_entry>;
  friend class DirectoryBuilder;

  Directory(std::filesystem::path path) : path{path} {}

  std::filesystem::path path;
  Entries childDirectories;
  Entries files;
  Entries symLinks;

public:
  void listItems();
};
} // namespace nb