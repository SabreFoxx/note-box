#pragma once
#include "views/cascade-draw.hpp"

namespace nb {
struct FileView : public CascadeDraw {
  void draw() override;
	void drawCurrent();

  void drawBackground();
  void drawForeground();
};
} // namespace nb
