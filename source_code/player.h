#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "bullet.h"

class Player {
private:
    sf::Texture texture;
    struct Movement {
        sf::Vector2f vector;
        int yIndex;
    };
    std::map<sf::Keyboard::Key, Movement> movementMap;

    int width = 64; // width of the sprite 
    int height = 64; // height of the sprite
    sf::Vector2i size;

    float playerSpeed = 1.0f;
    float maxFireRate = 150.0f;
    float fireRateTimer = 0;
    sf::RectangleShape boundingRectangle;
    std::vector<Bullet> bullets;


public:
    int xIndex = 0; // sprite sheet x index
    int yIndex = 0; // sprite sheet y index
    sf::Sprite sprite;

public:
    void Initialize();
    void Load();
    void Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition, sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);
};