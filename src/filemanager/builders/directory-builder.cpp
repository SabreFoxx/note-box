#include "directory-builder.h"
#include <exception.hpp>
#include <iostream>

using namespace nb;
using namespace std::filesystem;

DirectoryBuilder::DirectoryBuilder()
    : workingDirectory{filesystem::current_path()} {}

Directory DirectoryBuilder::loadDirectory(filesystem::path directoryPath) {
  if (!filesystem::exists(directoryPath)) {
    throw Exception{"Directory not found on file system"};
  } else {
    auto fileStatus = status(directoryPath);

    if (fileStatus.type() == file_type::regular)
      directoryPath = directoryPath.parent_path();
    if (!(status(directoryPath).type() == file_type::directory))
      throw RareException{"Could not discover directory, although file exists"};

    Directory directory{directoryPath};
    for (auto &entry : std::filesystem::directory_iterator(".")) {
      if (entry.is_regular_file())
        directory.files.push_back(entry);
      else if (entry.is_directory())
        directory.childDirectories.push_back(entry);
      else if (entry.is_symlink())
        directory.symLinks.push_back(entry);
    }

    return directory;
  }

  // check if directory exists; if it doesn't, throw exception
  // if it exists and its a file, use its parent directory as directoryPath
  // if it does, read all files in it create StorageObjects for them and store
  // in Directory object
}

Directory DirectoryBuilder::createDirectory() {
  // check if the directory exists in fs
  // if it does, loadDirectory
  // if it doesn't, create it, starting from each parent path fragment
  // once created, loadDirectory
  return Directory{""};
}
