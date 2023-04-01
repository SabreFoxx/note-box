#include "app.h"
#include "drawing/cascade-draw.hpp"
#include "filemanager/file/file.hpp"
#include <exception>
#include <memory>
#include <vector>
using namespace nb;
using namespace sf;
using namespace std;

template <typename T> void printName(StorageObject<T> &storageObject) {
  storageObject.sayName();
}

struct App::Impl {
  using Drawings = unique_ptr<CascadeDraw>;

  Impl(RenderWindow &window) : window{window} {}
  ~Impl() {}

  void init() {
    Folder folder{"workspapce"};
    File file{"exec.js"};
    printName(folder);
    printName(file);

    if (!font.loadFromFile("assets/fonts/DejaVuSansMono.ttf"))
      throw new std::exception{};
    welcomeText.setString("Welcome to notebox");
    welcomeText.setFont(getActiveFont());
  }

  void draw() {
    for (auto &drawing : drawings) {
      drawing->draw();
    }
    window.draw(welcomeText);
  }

  const Font &getActiveFont() { return font; }

  Font font{};
  Text welcomeText{};
  RenderWindow &window;
  vector<Drawings> drawings;
};

App::App(RenderWindow &window) : impl{new Impl{window}} {}
App::~App() = default;

void App::init() { impl->init(); }
void App::drawScreen() { impl->draw(); }
const Font &App::getActiveFont() { return impl->getActiveFont(); }
