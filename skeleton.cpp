#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize() {
    movementMap = {
        {sf::Keyboard::I, {sf::Vector2f(0, -1),0}}, // up
        {sf::Keyboard::J, {sf::Vector2f(-1, 0),1}}, // left
        {sf::Keyboard::K, {sf::Vector2f(0, 1),2}}, // down
        {sf::Keyboard::L, {sf::Vector2f(1, 0),3}} // right
    };

    size = sf::Vector2i(64, 64); // size of skeleton sprite
    sprite.scale(sf::Vector2f(3, 3)); // scale 

    // bounding rectangle properties
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Cyan);
    boundingRectangle.setOutlineThickness(1);
    boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

void Skeleton::Load() { // load skeleton texture
    if (texture.loadFromFile("assets/skeleton/texture/spriteSheet.png")) {
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(300, 200));
        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        std::cout << "Skeleton texture loaded!" << std::endl;
    }
    else {
        std::cout << "Skeleton texture failed to loaded!" << std::endl;
    }

    // load font for stats
    if (font.loadFromFile("assets/fonts/Alef-Regular.ttf")) {
        std::cout << "font loaded" << std::endl;
        stats.setFont(font);
    }
    else {
        std::cout << "font not loaded" << std::endl;
    }

    // set stats properties
    stats.setString("Health: " + std::to_string(health));
    stats.setPosition(sprite.getPosition() - sf::Vector2f(0, 40));
}

void Skeleton::Update(float deltaTime) {
    if (health >= 0) { // check if skeleton is alive
        for (const auto& [key, movement] : movementMap) { // update skeleton position and sprite
            if (sf::Keyboard::isKeyPressed(key)) {
                sf::Vector2f position = sprite.getPosition();

                yIndex = movement.yIndex;
                sprite.setPosition(position + movement.vector * skeletonSpeed * deltaTime);
                sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
                stats.setPosition(sprite.getPosition() - sf::Vector2f(0, 40)); // update stats position with skeleton position
            }
        }
        boundingRectangle.setPosition(sprite.getPosition()); // copy skeleton position to the bounding rectangle
    }
}

void Skeleton::Draw(sf::RenderWindow& window) {
    if (health >= 0) { // check if skeleton is alive
        window.draw(sprite);
        window.draw(boundingRectangle);
        window.draw(stats);
    }
}