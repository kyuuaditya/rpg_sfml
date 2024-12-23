#pragma once
#include <SFML/Graphics.hpp>

class Stats{
    private:
    sf::Text frameRate;
    sf::Font font;
    sf::Clock clock;
    sf::Clock clock2;
    float deltaTimeSmooth = 0;
    int nFrames= 0;
    // float frameRateSmooth = 0;

    public:
    float deltaTime = 0;
    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};