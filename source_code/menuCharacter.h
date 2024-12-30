#pragma once 
#include <SFML/Graphics.hpp>

class Character {
private:
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Vector2i size = sf::Vector2i(60, 60);
    int scale = 3;

    int yIndex = 2;
    int xIndex = 0;

    float animationSpeed = 0.01f;
    float elapsedTime = 0.0f;

    int xCharacter = 0;
    int direction = 1;

public:

public:
    void Initialize();
    void Load();
    void Update(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);
};