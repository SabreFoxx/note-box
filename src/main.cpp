#include "app.h"
#include <SFML/Graphics.hpp>
#include <exception>

using namespace nb;

int main(int argc, char *argv[]) {
  sf::Vector2u resolution{960, 540};
  sf::RenderWindow window{sf::VideoMode{resolution}, "Note Box"};
  App app{window};
  try {
    app.init();
  } catch (std::exception e) {
    return EXIT_FAILURE;
  }

  sf::Event mainEvent;
  while (window.isOpen()) {
    while (window.pollEvent(mainEvent)) {
      if (mainEvent.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    app.drawScreen();
    window.display();
  }

  return EXIT_SUCCESS;
}
