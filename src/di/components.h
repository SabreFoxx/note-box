#pragma once

#include "app.h"
#include <SFML/Graphics.hpp>
#include <fruit/fruit.h>

fruit::Component<sf::RenderWindow> getWindow();
fruit::Component<nb::Application> getApp();

