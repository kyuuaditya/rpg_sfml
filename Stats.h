#pragma once
#include <SFML/Graphics.hpp>

class Stats{
    private:
    sf::Text frameRate;
    sf::Font font;
    sf::Clock clock;
    
    float deltaTimeGap =0;
    int nFrames= 0;
    int updateTime = 500;
    int x = 10;
    int y = 10;

    public:
    float deltaTime = 0;
    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};