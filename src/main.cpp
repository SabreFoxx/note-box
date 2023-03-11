#include <SFML/Graphics.hpp>

int main(int argc, char *argv[]) {
  sf::Vector2u resolution{960, 540};
  sf::RenderWindow window{sf::VideoMode{resolution}, "Note Box"};
  sf::Font defaultFont;
  if (!defaultFont.loadFromFile("assets/fonts/DejaVuSansMono.ttf"))
    return EXIT_FAILURE;
  sf::Text welcomeText{"Welcome to notebox", defaultFont};

  sf::Event mainEvent;
  while (window.isOpen()) {
    while (window.pollEvent(mainEvent)) {
      if (mainEvent.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(welcomeText);
    window.display();
  }

  return EXIT_SUCCESS;
}
