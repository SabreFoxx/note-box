#include "components.h"

using namespace nb;
using namespace sf;
using namespace fruit;

Component<RenderWindow> getWindow() {
  return createComponent().registerProvider([]() {
    Vector2u initialResolution{960, 540};
    return new RenderWindow{VideoMode{initialResolution}, "Note Box"};
  });
}

Component<Application> getApp() {
	return createComponent().install(getAppImplComponent).install(getWindow);
}