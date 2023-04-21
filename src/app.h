#pragma once
#include <SFML/Graphics.hpp>
#include <fruit/fruit.h>
#include <memory>

namespace nb {
struct Application {
  Application(sf::RenderWindow *window) : window{window} {};
  ~Application() = default;

  virtual void init() = 0;
  virtual void draw() = 0;
  sf::RenderWindow *window;
  // TODO try to access a property directly from here
  // const sf::Font &getActiveFont();

  // private:
  //   struct Impl;
  //   std::unique_ptr<Impl> impl;
};
} // namespace nb

fruit::Component<fruit::Required<sf::RenderWindow>, nb::Application>
getAppImplComponent();