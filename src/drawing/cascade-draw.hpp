#pragma once
#include <vector>

namespace nb {
struct CascadeDraw {
  virtual void draw() = 0;
  virtual ~CascadeDraw() = default;

private:
  virtual void drawBackground() = 0;
  virtual void drawForeground() = 0;

protected:
  std::vector<CascadeDraw> childrenDrawings;
};

} // namespace nb
