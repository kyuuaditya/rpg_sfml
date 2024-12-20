#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player {
private:
    sf::Texture texture;
    struct Movement {
        sf::Vector2f vector;
        int yIndex;
    };
    std::map<sf::Keyboard::Key, Movement> movementMap;

    float width = 64;
    float height = 64;
    sf::Vector2i size;

    float bulletSpeed = 0.5f;
    float playerSpeed = 2.0f;
    sf::RectangleShape boundingRectangle;
    std::vector<sf::RectangleShape> bullets;


public:
    int xIndex = 0;
    int yIndex = 0;
    sf::Sprite sprite;

public:
    void Initialize();
    void Load();
    void Update(float deltaTime, Skeleton& skeleton);
    void Draw(sf::RenderWindow& window);
};