#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player {
private:
    sf::Texture texture;

    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 0.5f;

public:
    sf::Sprite sprite;

public:
    void Initialize();
    void Load();
    void Update(Skeleton& skeleton);
    void Draw(sf::RenderWindow& window);
};

// #pragma once 
// #include <SFML/Graphics.hpp>

// class Player {
// private:
//     struct Movement {
//         sf::Vector2f vector;
//         int yIndex;
//     };
//     sf::Texture texture;
//     std::map<sf::Keyboard::Key, Movement> movementMap;

// public:
//     int xIndex;
//     int yIndex;
//     sf::Sprite sprite;

// public:
//     void Initialize();
//     void Load();

//     void Update();
//     void Draw();
//     sf::Sprite& getSprite();
// };