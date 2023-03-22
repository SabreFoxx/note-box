#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

namespace nb {
struct App {
  App(sf::RenderWindow &window);
  ~App();

void init();
  void drawScreen();
  const sf::Font &getActiveFont();

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};
} // namespace nb