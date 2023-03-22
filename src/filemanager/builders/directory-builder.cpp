#include "directory-builder.h"

using namespace nb;
using namespace std::filesystem;

DirectoryBuilder::DirectoryBuilder(::path directoryPath)
    : path{directoryPath, path::generic_format},
      workingDirectory{filesystem::current_path()} {}