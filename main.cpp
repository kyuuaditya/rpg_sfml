// to run and compiler
// mingw32-make
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"
#include "Stats.h"

int main() {
    //-------------------------------- INITIALIZE --------------------------------
    bool isFullscreen = false;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Main menu", sf::Style::Default, settings);

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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F) {
                isFullscreen = !isFullscreen;
                window.close();
                window.create(
                    isFullscreen ? sf::VideoMode(1920, 1080) : sf::VideoMode(1280, 720),
                    "Main menu",
                    isFullscreen ? sf::Style::Fullscreen : sf::Style::Default,
                    settings
                );
            }
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