#pragma once
#include <vector>

namespace nb {
struct CascadeDraw {
  virtual void draw() = 0;
  virtual ~CascadeDraw() = default;

protected:
  std::vector<CascadeDraw> childrenDrawings;
};

} // namespace nb
