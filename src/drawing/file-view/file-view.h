#pragma once
#include "drawing/cascade-draw.hpp"

namespace nb {
struct FileView : CascadeDraw {
  void draw() override;
	void drawCurrent();

  void drawBackground() override;
  void drawForeground() override;
};
} // namespace nb
