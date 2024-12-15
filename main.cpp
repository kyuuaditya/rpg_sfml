#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Skeleton.h"

int main() {
    //-------------------------------- INITIALIZE --------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "RPG Game", sf::Style::Default, settings);
    //-------------------------------- INITIALIZE --------------------------------

    Player player;
    Skeleton skeleton;

    //-------------------------------- INITIALIZE --------------------------------
    player.Initialize();
    skeleton.Initialize();
    //-------------------------------- INITIALIZE --------------------------------

    //-------------------------------- LOAD --------------------------------
    player.Load();
    skeleton.Load();
    //-------------------------------- LOAD --------------------------------

    while (window.isOpen()) {
        //-------------------------------- UPDATE --------------------------------
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        skeleton.Update();
        player.Update(skeleton);
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

// // to run and compiler
// // mingw32-make
// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <map>
// #include <windows.h>
// #include <math.h>
// #include "player.h"
// #include "skeleton.h"
// using namespace std;

// // function to normalize a vector
// sf::Vector2f normalizeVector(sf::Vector2f vector) {
//     float vec = sqrt(vector.x * vector.x + vector.y * vector.y);
//     sf::Vector2f normalizedVector;
//     normalizedVector.x = vector.x / vec;
//     normalizedVector.y = vector.y / vec;
//     return normalizedVector;
// }

// int main() {
//     AllocConsole();
//     freopen("CONOUT$", "w", stdout);
//     freopen("CONOUT$", "w", stderr);

//     std::cout << "works here" << std::endl;
//     // createing a log file
//     ofstream log;
//     log.open("log.txt");

//     // ------------------ Initialization ------------------
//     sf::ContextSettings settings;
//     settings.antialiasingLevel = 8; // set the antialiasing level

//     // used to create the main window
//     sf::RenderWindow window(sf::VideoMode(1280, 720), "RPG", sf::Style::Default, settings);

//     Player player;
//     player.Initialize();
//     player.Load();

//     Skeleton skeleton;
//     skeleton.Initialize1();
//     skeleton.Load1();
//     // ------------------ Initialization ------------------


//     // -------------------- Variables --------------------
//     std::vector<sf::RectangleShape> bullets;
//     float bulletSpeed = 0.3f;
//     // -------------------- Variables --------------------

//     //main loop
//     while (window.isOpen()) {

//         // ?--------------- Update ------------------
//         //close code
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close(); // close the window
//             }
//         }

//         // // bullet on mouse click
//         // if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
//         //     bullets.push_back(sf::RectangleShape(sf::Vector2f(20, 20)));
//         //     int i = bullets.size() - 1;
//         //     bullets[i].setPosition(player.sprite.getPosition());
//         // }
//         // for (size_t i = 0;i < bullets.size();i++) {
//         //     sf::Vector2f bulletDirection = skeleton.ssprite.getPosition() - bullets[i].getPosition();
//         //     bulletDirection = normalizeVector(bulletDirection);
//         //     bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
//         // }

//         player.Update();
//         skeleton.Update1();
//         // ?--------------- Update ------------------

//         // ----------------- Draw -------------------
//         window.clear(sf::Color::Black); // clear the previous frame

//         for (size_t i = 0;i < bullets.size();i++) {
//             window.draw(bullets[i]);
//         }

//         player.Draw();
//         skeleton.Draw1(window);

//         window.draw(player.sprite);
//         // window.draw(skeleton.ssprite);

//         window.display(); // display the current frame
//         // ----------------- Draw -------------------
//     }
//     return 0;
// }