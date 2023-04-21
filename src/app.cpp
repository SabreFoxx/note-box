#include "app.h"
#include "drawing/cascade-draw.hpp"
#include "filemanager/file/file.hpp"
#include <exception>
#include <memory>
#include <vector>
using namespace nb;
using namespace sf;
using namespace std;
using namespace fruit;

template <typename T> void printName(StorageObject<T> &storageObject) {
  storageObject.sayName();
}

struct ApplicationImpl : public Application {
  using Drawings = unique_ptr<CascadeDraw>;

  INJECT(ApplicationImpl(RenderWindow *window)) : Application{window} {}
  ~ApplicationImpl() {}

  virtual void init() override {
    Folder folder{"workspapce"};
    File file{"exec.js"};
    printName(folder);
    printName(file);

    if (!font.loadFromFile("assets/fonts/DejaVuSansMono.ttf"))
      throw new std::exception{};
    welcomeText.setString("Welcome to notebox");
    welcomeText.setFont(getActiveFont());
  }

  virtual void draw() override {
    for (auto &drawing : drawings) {
      drawing->draw();
    }
    window->draw(welcomeText);
  }

  const Font &getActiveFont() { return font; }

  Font font{};
  Text welcomeText{};
  vector<Drawings> drawings;
};

Component<Required<RenderWindow>, Application> getAppImplComponent() {
  return createComponent().bind<Application, ApplicationImpl>();
}

// Application::Application(RenderWindow *window) : impl{new Impl{window}} {}
// Application::~Application() = default;

// void Application::init() { impl->init(); }
// void Application::drawScreen() { impl->draw(); }
// const Font &Application::getActiveFont() { return impl->getActiveFont(); }
