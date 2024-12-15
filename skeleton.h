#pragma once
#include <SFML/Graphics.hpp>

class Skeleton {
private:
    sf::Texture texture;
    struct Movement1 {
        sf::Vector2f vector;
        int yIndex;
    };
    std::map<sf::Keyboard::Key, Movement1> movementMap;

public:
    sf::Sprite sprite;
    int xIndex;
    int yIndex;

public:
    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};