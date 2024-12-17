#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player {
private:
    struct Movement {
        sf::Vector2f vector;
        int yIndex;
    };
    std::map<sf::Keyboard::Key, Movement> movementMap;
    sf::Texture texture;


    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 0.5f;

    sf::RectangleShape boundingRectangle;

    float width = 64;
    float height = 64;

    sf::Vector2i size;

public:
    sf::Sprite sprite;
    int xIndex = 0;
    int yIndex = 0;


public:
    void Initialize();
    void Load();
    void Update(Skeleton& skeleton);
    void Draw(sf::RenderWindow& window);
};