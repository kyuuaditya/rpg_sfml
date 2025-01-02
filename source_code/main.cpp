// to run and compiler
// mingw32-make
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "Player.h"
#include "Skeleton.h"
#include "Stats.h"
#include "menuCharacter.h"

// function to check if the mouse is over the RectangleShape button
bool isMouseOverButton(const sf::RectangleShape& button, sf::Vector2f& mousePos) {
    return button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

int main() {
    //-------------------------------- INITIALIZE --------------------------------
    sf::Vector2f playButtonSize(150, 60);
    sf::Vector2f exitButtonSize(150, 60);

    bool isOnMainMenu = true;

    bool isFullscreen = false;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Main menu", sf::Style::Default, settings);
    window.setFramerateLimit(144); // set frame rate limit
    window.setVerticalSyncEnabled(true); // enable vertical sync

    Character character;
    Player player;
    Skeleton skeleton;
    Stats stats;

    character.Initialize();
    player.Initialize();
    skeleton.Initialize();
    stats.Initialize();

    sf::RectangleShape playButton(sf::Vector2f(playButtonSize.x, playButtonSize.y)); // play button
    playButton.setFillColor(sf::Color::Cyan);
    playButton.setOutlineColor(sf::Color::White); // Set outline color to red
    playButton.setOutlineThickness(3.0f);

    sf::Text playButtonText;
    std::string playButtonTextString = "PLAY";
    playButtonText.setFont(stats.font);
    playButtonText.setCharacterSize(36);
    playButtonText.setFillColor(sf::Color::Black);
    playButtonText.setString(playButtonTextString);

    sf::RectangleShape exitButton(sf::Vector2f(exitButtonSize.x, exitButtonSize.y)); // play button
    exitButton.setFillColor(sf::Color::Cyan);
    exitButton.setOutlineColor(sf::Color::White); // Set outline color to red
    exitButton.setOutlineThickness(3.0f);

    sf::Text exitButtonText;
    std::string exitButtonTextString = "EXIT";
    exitButtonText.setFont(stats.font);
    exitButtonText.setCharacterSize(36);
    exitButtonText.setFillColor(sf::Color::Black);
    exitButtonText.setString(exitButtonTextString);

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    //-------------------------------- INITIALIZE --------------------------------

    //-------------------------------- LOAD --------------------------------
    character.Load();
    player.Load();
    skeleton.Load();
    stats.Load();

    if (backgroundTexture.loadFromFile("assets/background/mainBackground.png")) { // load background texture
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setPosition(sf::Vector2f(0, 0));
        backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
        std::cout << "background texture loaded!" << std::endl;
    }
    else {
        std::cout << "background texture failed to loaded!" << std::endl;
    }

    //-------------------------------- LOAD --------------------------------

    while (window.isOpen()) {
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
        //-------------------------------- EVENTS --------------------------------
        sf::Event event;
        while (window.pollEvent(event)) { // all events
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) { // key events
                if (event.key.code == sf::Keyboard::F) { // to toggle fullscreen
                    isFullscreen = !isFullscreen;
                    window.close();
                    window.create(
                        isFullscreen ? sf::VideoMode(1920, 1080) : sf::VideoMode(1280, 720),
                        "Main menu",
                        isFullscreen ? sf::Style::Fullscreen : sf::Style::Default,
                        settings
                    );
                    window.setFramerateLimit(144);
                    window.setVerticalSyncEnabled(true);
                }
                if (event.key.code == sf::Keyboard::Enter) { // to select the play button
                    isOnMainMenu = false;
                }
                if (event.key.code == sf::Keyboard::Escape) { // to go back to the main menu
                    isOnMainMenu = !isOnMainMenu;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { // mouse events (left)
                if (isMouseOverButton(playButton, mousePosition)) {
                    isOnMainMenu = false;
                    if (skeleton.health <= 0) {
                        skeleton.health = 100;
                        skeleton.stats.setString("Health: " + std::to_string(skeleton.health));
                        skeleton.sprite.setTextureRect(sf::IntRect(skeleton.xIndex * skeleton.size.x, skeleton.yIndex * skeleton.size.y, skeleton.size.x, skeleton.size.y));
                    }
                }
                if (isMouseOverButton(exitButton, mousePosition)) {
                    window.close();
                }
            }
        }
        //-------------------------------- EVENTS --------------------------------

        // -------------------------------- MAIN MENU --------------------------------
        if (isOnMainMenu) {
            playButton.setPosition(sf::Vector2f(window.getSize().x / 2 - playButtonSize.x / 2, window.getSize().y / 3 - playButtonSize.y / 2));
            playButtonText.setPosition(playButton.getPosition().x + playButtonSize.x / 2 - playButtonText.getLocalBounds().width / 2, playButton.getPosition().y + playButtonSize.y / 2 - playButtonText.getLocalBounds().height);
            exitButton.setPosition(sf::Vector2f(window.getSize().x / 2 - exitButtonSize.x / 2, window.getSize().y / 3 * 2 - exitButtonSize.y / 2));
            exitButtonText.setPosition(exitButton.getPosition().x + exitButtonSize.x / 2 - exitButtonText.getLocalBounds().width / 2, exitButton.getPosition().y + exitButtonSize.y / 2 - exitButtonText.getLocalBounds().height);
            stats.Update();
            character.Update(window);
            //-------------------------------- DRAW --------------------------------
            window.clear(sf::Color::Black);
            window.draw(playButton);
            window.draw(playButtonText);
            window.draw(exitButton);
            window.draw(exitButtonText);
            character.Draw(window);
            stats.Draw(window);
            window.display();
            //-------------------------------- DRAW --------------------------------
        }
        // -------------------------------- MAIN MENU --------------------------------
        // -------------------------------- GAME --------------------------------
        if (!isOnMainMenu) {
            stats.Update();
            skeleton.Update(stats.deltaTime, window);
            player.Update(stats.deltaTime, skeleton, mousePosition, window);

            //-------------------------------- DRAW --------------------------------
            window.clear(sf::Color::Black);

            window.draw(backgroundSprite); // draw background

            skeleton.Draw(window);
            player.Draw(window);
            stats.Draw(window);

            window.display();
            //-------------------------------- DRAW --------------------------------
        }
        // -------------------------------- GAME --------------------------------
    }
    return 0;
}