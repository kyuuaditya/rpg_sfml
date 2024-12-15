#pragma once
#include <SFML/Graphics.hpp>

class Skeleton {
private:
    sf::Texture texture;

public:
    sf::Sprite sprite;

public:
    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};

// #pragma once 
// #include <SFML/Graphics.hpp>

// class Skeleton {
// private:
//     struct Movement1 {
//         sf::Vector2f vector;
//         int yIndex;
//     };
//     sf::Texture stexture;
//     std::map<sf::Keyboard::Key, Movement1> movementMap2;

// public:
//     int xeIndex;
//     int yeIndex;
//     sf::Sprite ssprite;

// public:
//     void Initialize1();
//     void Load1();

//     void Update1();
//     void Draw1(sf::RenderWindow& window);
//     sf::Sprite& getSprite();
// };