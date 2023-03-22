#pragma once
#include <filesystem>
#include <iostream>

namespace nb {
template <typename FileType> struct StorageObject {
  StorageObject(std::string name) : name{name} {}
  void sayName() { static_cast<FileType *>(this)->sayNameImpl(); }

  std::filesystem::path p;
  std::string name;
};

struct File : StorageObject<File> {
	File(std::string name) : StorageObject<File>{name} {}
  void sayNameImpl() { std::cout << "My name is " << name << std::endl; }
};

struct Folder : StorageObject<Folder> {
  Folder(std::string name) : StorageObject<Folder>{name} {}
  void sayNameImpl() { std::cout << "My folder name is " << name << std::endl; }
};

struct Link : StorageObject<Link> {
  Link(std::string name) : StorageObject<Link>{name} {}
  void sayNameImpl() { std::cout << "My link's name is " << name << std::endl; }
};

} // namespace nb
