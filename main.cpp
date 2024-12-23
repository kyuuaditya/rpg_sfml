// to run and compiler
// mingw32-make
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"
#include "Stats.h"

int main() {
    //-------------------------------- INITIALIZE --------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // set antialiasing level
    sf::RenderWindow window(sf::VideoMode(1280, 720), "RPG Game", sf::Style::Default, settings); // set screen resolution
    // window.setFramerateLimit(144); // set frame limit
    
    Player player;
    Skeleton skeleton;
    Stats stats;

    player.Initialize();
    skeleton.Initialize();
    stats.Initialize();
    
    //-------------------------------- INITIALIZE --------------------------------

    //-------------------------------- LOAD --------------------------------
    player.Load();
    skeleton.Load();
    stats.Load();
    
    //-------------------------------- LOAD --------------------------------

    while (window.isOpen()) {
        
        //-------------------------------- UPDATE --------------------------------
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        stats.Update();
        skeleton.Update(stats.deltaTime);
        player.Update(stats.deltaTime, skeleton);
        //-------------------------------- UPDATE --------------------------------

        //-------------------------------- DRAW --------------------------------
        window.clear(sf::Color::Black);

        skeleton.Draw(window);
        player.Draw(window);
        stats.Draw(window);

        window.display();
        //-------------------------------- DRAW --------------------------------
    }
    return 0;
}