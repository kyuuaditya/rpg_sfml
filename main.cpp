// to run and compiler
// mingw32-make
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"

int main() {
    //-------------------------------- INITIALIZE --------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // set antialiasing level
    sf::RenderWindow window(sf::VideoMode(1280, 720), "RPG Game", sf::Style::Default, settings); // set screen resolution
    window.setFramerateLimit(144); // set frame limit
    
    Player player;
    Skeleton skeleton;

    player.Initialize();
    skeleton.Initialize();
    //-------------------------------- INITIALIZE --------------------------------

    //-------------------------------- LOAD --------------------------------
    player.Load();
    skeleton.Load();
    //-------------------------------- LOAD --------------------------------
    
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTimeTimer =  clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();
        
        //-------------------------------- UPDATE --------------------------------
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton);
        //-------------------------------- UPDATE --------------------------------

        //-------------------------------- DRAW --------------------------------
        window.clear(sf::Color::Black);

        skeleton.Draw(window);
        player.Draw(window);

        window.display();
        //-------------------------------- DRAW --------------------------------
    }
    return 0;
}