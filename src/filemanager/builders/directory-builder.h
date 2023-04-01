#pragma once
#include "filemanager/directory/directory.h"
#include "filemanager/file/file.hpp"
#include <filesystem>
#include <vector>

namespace nb {
using namespace std;

struct DirectoryBuilder {
  DirectoryBuilder();

  Directory loadDirectory(filesystem::path directoryPath);
  Directory createDirectory();

private:
  filesystem::path workingDirectory;
};
} // namespace nb