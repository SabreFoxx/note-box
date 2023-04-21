#include "file-view.h"
#include <iostream>

using namespace nb;
using namespace std;

void FileView::draw() {
  drawBackground();

  for (auto &drawing : childrenDrawings) {
    drawing.draw();
  }
  drawForeground();
}

void FileView::drawCurrent() {}

void FileView::drawBackground() { cout << "hello there" << endl; }

void FileView::drawForeground() {}
