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

    std::cout << "0: Windowed" << std::endl << "1: Fullscreen" << std::endl;
    int input_mode = 0;// default windowed mode
    std::cin >> input_mode;

    int width = 1280; // default windowed mode 720p
    int height = 720;
    sf::Uint32 style = sf::Style::Default;

    if (input_mode) { // fullscreen mode 1080p
        width = 1920;
        height = 1080;
        style = sf::Style::Fullscreen;
    }
    else { // windowed mode 720p
        width = 1280;
        height = 720;
        style = sf::Style::Titlebar | sf::Style::Close;
    }

    sf::RenderWindow window(sf::VideoMode(width, height), "RPG Game", style, settings); // set screen resolution

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