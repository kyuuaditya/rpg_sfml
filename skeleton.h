#pragma once
#include <SFML/Graphics.hpp>

class Skeleton {
private:
    sf::Texture texture;
    struct Movement {
        sf::Vector2f vector;
        int yIndex;
    };
    std::map<sf::Keyboard::Key, Movement> movementMap;

    float skeletonSpeed = 2.0f;
    float width = 64;
    float height = 64;
    sf::Vector2i size;

public:
    int xIndex;
    int yIndex;
    sf::Sprite sprite;
    sf::RectangleShape boundingRectangle;

public:
    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
};