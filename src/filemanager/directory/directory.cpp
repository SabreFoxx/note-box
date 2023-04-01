#include "directory.h"
#include <iostream>

using namespace nb;
using namespace std;

void Directory::listItems() {
  for (auto &item : childDirectories) {
    cout << item.path().filename() << endl;
  }
}