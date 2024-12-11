// to run and compiler
// mingw32-make
#include <SFML/Graphics.hpp>
#include <fstream>
#include <map>
using namespace std;

int main() {

    // createing a log file
    ofstream log;
    log.open("log.txt");

    // ------------------ Initialization ------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // set the antialiasing level

    sf::RenderWindow window(sf::VideoMode(1080, 720), "RPG", sf::Style::Default, settings); // used to create the main window

    // ------------------ Initialization ------------------

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
    int xIndex = 0;
    int yIndex = 0;
    // ?-------------------- Configs ----------------------

    // ------------------- Load Assets --------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    // importing player texture
    if (playerTexture.loadFromFile("assets/player/texture/spriteSheet.png")) {
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(64 * xIndex, 64 * yIndex, 64, 64));
        playerSprite.scale(sf::Vector2f(5, 5));
        log << "player texure loaded" << endl;
    }
    else {
        log << "Error loading player texture" << endl;
    }
    // ------------------- Load Assets --------------------

    //main loop
    while (window.isOpen()) {

        // ?--------------- Update ------------------
        //checks for events every frame
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
        // ?--------------- Update ------------------

        // ----------------- Draw -------------------
        window.clear(sf::Color::Black); // clear the previous frame
        // drawing everything
        playerSprite.setTextureRect(sf::IntRect(64 * xIndex, 64 * yIndex, 64, 64));
        window.draw(playerSprite);
        window.display(); // display the current frame
        // ----------------- Draw -------------------

    }
    return 0;
}