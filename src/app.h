#pragma once

#include "views/cascade-draw.hpp"
#include <SFML/Graphics.hpp>
#include <fruit/fruit.h>
#include <memory>

namespace nb {
struct Application {
  Application(sf::RenderWindow *window, CascadeDraw *mainView)
      : window{window}, mainView{mainView} {};
  ~Application() = default;

  virtual void init() = 0;
  virtual void draw() = 0;

  CascadeDraw *mainView;
  sf::RenderWindow *window;
};
} // namespace nb

fruit::Component<fruit::Required<sf::RenderWindow, nb::CascadeDraw>,
                 nb::Application>
getAppImplComponent();