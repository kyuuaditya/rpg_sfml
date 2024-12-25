#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
public:
    float speed = 1.0f; // bullet speed
    sf::Vector2f direction = sf::Vector2f(0, 0);

private:
    sf::RectangleShape rectangleShape;
    // sf::Vector2f direction;

public:
    void Initialize(const sf::Vector2f& position, sf::Vector2f& direction, float speed);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

    inline sf::FloatRect GetGlobalBounds() { return rectangleShape.getGlobalBounds(); }
};