// to run and compiler
// mingw32-make
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

// function to normalize a vector
sf::Vector2f normalizeVector(sf::Vector2f vector) {
    float vec = sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / vec;
    normalizedVector.y = vector.y / vec;
    return normalizedVector;
}

int main() {
    // createing a log file
    ofstream log;
    log.open("log.txt");

    // ------------------ Initialization ------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // set the antialiasing level
    sf::RenderWindow window(sf::VideoMode(1280, 720), "RPG", sf::Style::Default, settings); // used to create the main window
    // ------------------ Initialization ------------------

    // -------------------- Variables --------------------
    int xIndex = 0;
    int yIndex = 0;
    int xeIndex = 0;
    int yeIndex = 0;
    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 0.2f;
    // -------------------- Variables --------------------

    // ?------------------- Configs ----------------------
    // movement structure to store speed and sprite index
    struct Movement {
        sf::Vector2f vector;
        int yIndex;
    };
    // map to store the movement related data of the player
    std::map<sf::Keyboard::Key, Movement> movementMap = {
        {sf::Keyboard::W, {sf::Vector2f(0, -1),0}}, // up
        {sf::Keyboard::A, {sf::Vector2f(-1, 0),1}}, // left
        {sf::Keyboard::S, {sf::Vector2f(0, 1),2}}, // down
        {sf::Keyboard::D, {sf::Vector2f(1, 0),3}} // right
    };
    std::map<sf::Keyboard::Key, Movement> movementMap2 = {
        {sf::Keyboard::I, {sf::Vector2f(0, -1),0}}, // up
        {sf::Keyboard::J, {sf::Vector2f(-1, 0),1}}, // left
        {sf::Keyboard::K, {sf::Vector2f(0, 1),2}}, // down
        {sf::Keyboard::L, {sf::Vector2f(1, 0),3}} // right
    };
    // ?-------------------- Configs ----------------------

    // ------------------- Load Assets --------------------
    // ?-------------------- Skeleton ---------------------
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;
    if (skeletonTexture.loadFromFile("assets/skeleton/texture/spriteSheet.png")) {
        skeletonSprite.setTexture(skeletonTexture);
        skeletonSprite.setPosition(sf::Vector2f(1000, 200));
        skeletonSprite.setTextureRect(sf::IntRect(64 * xeIndex, 64 * yeIndex, 64, 64));
        skeletonSprite.scale(sf::Vector2f(2, 2));
        log << "skeleton texure loaded" << endl;
    }
    else {
        log << "Error loading skeleton texture" << endl;
    }
    // ?-------------------- Skeleton ---------------------

    // ?--------------------- Player ----------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    // importing player texture
    if (playerTexture.loadFromFile("assets/player/texture/spriteSheet.png")) {
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(64 * xIndex, 64 * yIndex, 64, 64));
        playerSprite.scale(sf::Vector2f(2, 2));
        playerSprite.setPosition(sf::Vector2f(200, 600));
        log << "player texure loaded" << endl;
    }
    else {
        log << "Error loading player texture" << endl;
    }
    // ?--------------------- Player ----------------------
    // ------------------- Load Assets --------------------

    //main loop
    while (window.isOpen()) {

        // ?--------------- Update ------------------
        //close code
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // close the window
            }
        }
        // movement of player
        for (const auto& [key, movement] : movementMap) {
            if (sf::Keyboard::isKeyPressed(key)) {
                sf::Vector2f position = playerSprite.getPosition();
                playerSprite.setPosition(position + movement.vector);
                yIndex = movement.yIndex;
            }
        }
        // movement of skeleton
        for (const auto& [key, movement] : movementMap2) {
            if (sf::Keyboard::isKeyPressed(key)) {
                sf::Vector2f position = skeletonSprite.getPosition();
                skeletonSprite.setPosition(position + movement.vector);
                yeIndex = movement.yIndex;
            }
        }
        // bullet on mouse click
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(20, 20)));
            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
        }
        for (size_t i = 0;i < bullets.size();i++) {
            sf::Vector2f bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
            bulletDirection = normalizeVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }
        // ?--------------- Update ------------------

        // ----------------- Draw -------------------
        window.clear(sf::Color::Black); // clear the previous frame

        playerSprite.setTextureRect(sf::IntRect(64 * xIndex, 64 * yIndex, 64, 64));
        skeletonSprite.setTextureRect(sf::IntRect(64 * xeIndex, 64 * yeIndex, 64, 64));
        window.draw(skeletonSprite);
        window.draw(playerSprite);

        // window.draw(bullet);
        for (size_t i = 0;i < bullets.size();i++) {
            window.draw(bullets[i]);
        }
        window.display(); // display the current frame
        // ----------------- Draw -------------------
    }
    return 0;
}