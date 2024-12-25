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

    float width = 64;
    float height = 64;
    sf::Vector2i size;

    float playerSpeed = 2.0f;
    float maxFireRate = 250.0f;
    float fireRateTimer = 0;
    sf::RectangleShape boundingRectangle;
    std::vector<Bullet> bullets;


public:
    int xIndex = 0;
    int yIndex = 0;
    sf::Sprite sprite;

public:
    void Initialize();
    void Load();
    void Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition);
    void Draw(sf::RenderWindow& window);
};