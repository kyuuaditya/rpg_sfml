#pragma once
#include <SFML/Graphics.hpp>

class Skeleton {
private:
    sf::Font font;
    sf::Texture texture;
    struct Movement {
        sf::Vector2f vector;
        int yIndex;
    };
    std::map<sf::Keyboard::Key, Movement> movementMap;

    float skeletonSpeed = 1.0f;
    float width = 64;
    float height = 64;

public:
    sf::Vector2i size = sf::Vector2i(64, 64);
    int xIndex = 0;
    int yIndex = 0;
    int health = 100;
    sf::Sprite sprite;
    sf::RectangleShape boundingRectangle;
    sf::Text stats;

public:
    void Initialize();
    void Load();
    void Update(float deltaTime, sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);
};