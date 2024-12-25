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
    sf::RenderWindow window(sf::VideoMode(1280, 720), "RPG Game", sf::Style::Default, settings);
    // window.setFramerateLimit(144); // set frame limit

    Player player;
    Skeleton skeleton;
    Stats stats;
    Bullet bullet;

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

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        stats.Update();
        skeleton.Update(stats.deltaTime);
        player.Update(stats.deltaTime, skeleton, mousePosition);
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