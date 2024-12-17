#pragma once
#include <SFML/Graphics.hpp>

class Math {
public:
    // normalize function
    static sf::Vector2f NormalizeVector(sf::Vector2f vector);

    // check collision function
    static bool DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2);
}; 