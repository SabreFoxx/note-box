#include "app.h"
#include "filemanager/builders/directory-builder.h"
#include "filemanager/directory/directory.h"
#include <SFML/Graphics.hpp>
#include <exception>
#include <filesystem>

#include "di/components.h"
#include <fruit/fruit.h>
using fruit::Component;
using fruit::Injector;

using namespace nb;

int main(int argc, char *argv[]) {
  Injector<Application, sf::RenderWindow> injector(getApp);
  Application *app{injector.get<Application *>()};
  sf::RenderWindow *window{injector.get<sf::RenderWindow *>()};

  try {
    app->init();
  } catch (std::exception e) {
    return EXIT_FAILURE;
  }

  try {
    DirectoryBuilder b{};
    Directory d = b.loadDirectory(std::filesystem::current_path());
    d.listItems();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  sf::Event mainEvent;
  while (window->isOpen()) {
    while (window->pollEvent(mainEvent)) {
      if (mainEvent.type == sf::Event::Closed)
        window->close();
    }

    window->clear();
    app->mainView->draw();
    window->display();
  }

  return EXIT_SUCCESS;
}
