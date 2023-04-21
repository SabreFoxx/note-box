#pragma once

#include <SFML/Graphics.hpp>
#include <fruit/fruit.h>
#include <vector>

namespace nb {
struct CascadeDraw {
  CascadeDraw(sf::RenderWindow *window) : window{window} {};
  virtual ~CascadeDraw() = default;
  virtual void draw() = 0;

  sf::RenderWindow *window;

protected:
  std::vector<CascadeDraw> childrenDrawings;
};

} // namespace nb

