#include "app.h"
// #include "views/cascade-draw.hpp"
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

  INJECT(ApplicationImpl(RenderWindow *window, CascadeDraw *mainView))
      : Application{window, mainView} {}
  ~ApplicationImpl() {}

  virtual void init() override {
    Folder folder{"workspapce"};
    File file{"exec.js"};
    printName(folder);
    printName(file);
  }

  virtual void draw() override {
    for (auto &drawing : drawings) {
      drawing->draw();
    }
  }

  // MainView *mainView;
  vector<Drawings> drawings;
};

Component<Required<RenderWindow, CascadeDraw>, Application> getAppImplComponent() {
  return createComponent().bind<Application, ApplicationImpl>();
}
