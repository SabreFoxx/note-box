#include "main-view.h"
#include "filemanager/file/file.hpp"
#include <exception>
#include <memory>
#include <vector>

using namespace nb;
using namespace sf;
using namespace fruit;
using namespace std;

namespace nb {
struct MainView : public CascadeDraw {
  MainView(sf::RenderWindow *window) : CascadeDraw{window} {

    if (!font.loadFromFile("assets/fonts/DejaVuSansMono.ttf"))
      throw new std::exception{};
    welcomeText.setString("Welcome to notebox");
    welcomeText.setFont(getActiveFont());
  }

  void draw() override { window->draw(welcomeText); }

  const Font &getActiveFont() { return font; }

  Font font{};
  Text welcomeText{};
};
} // namespace nb

Component<Required<RenderWindow>, CascadeDraw> getMainView() {
  // alternative to INJECT(MainView()) = default;
  return createComponent()
      .registerConstructor<MainView(RenderWindow *)>()
      .bind<CascadeDraw, MainView>();
}