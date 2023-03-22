#pragma once

#include "filemanager/file/file.h"

#include <filesystem>
#include <vector>

namespace nb {
using namespace std;

struct DirectoryBuilder {
  DirectoryBuilder(path directoryPath);

private:
  filesystem::path path;
	filesystem::path workingDirectory;
};
} // namespace nb