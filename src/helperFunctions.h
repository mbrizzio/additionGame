#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <string>
#include <sstream>
#include <iostream>

template <typename T>
concept HasOrigin = requires(T t, float x, float y) {
    {t.getGlobalBounds()};
    {t.setOrigin(x, y)};
};

template <HasOrigin T> 
void centerOrigin(T &object) {
    sf::FloatRect boundingBox = object.getGlobalBounds();

    object.setOrigin(boundingBox.left + boundingBox.width / 2.f, boundingBox.top + boundingBox.height / 2.f);
};