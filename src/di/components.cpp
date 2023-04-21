#include "components.h"
#include "views/cascade-draw.hpp"

using namespace nb;
using namespace sf;
using namespace fruit;

extern Component<Required<RenderWindow>, CascadeDraw> getMainView();

Component<RenderWindow> getWindow() {
  return createComponent().registerProvider([]() {
    Vector2u initialResolution{960, 540};
    // fruit will take ownership and call delete upon destruction
    return new RenderWindow{VideoMode{initialResolution}, "Note Box"};
  });
}

// RendeWindow is added as template argument to Component below, so we can pass getApp
// to an Injector<Application, RenderWindow> injector, which in turn lets us
// call separate injector.get<Application>() and injector.get<RenderWindow>(), without
// creating a new injector for each. We want to get the RenderWindow component defined
// in getWindow above; if we create a new injector in main.cpp without using
// a fruit::NormalizedComponent, we will create a duplicate sf::RenderWindow
// because each injector has new bindings for Components.
// NormalizedComponent helps us share bindings instead of creating new ones.
Component<Application, RenderWindow> getApp() {
  return createComponent()
      .install(getAppImplComponent)
      .install(getWindow)
      .install(getMainView);
}