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

void Skeleton::Load() {
    if (texture.loadFromFile("assets/skeleton/texture/spriteSheet.png")) {
        std::cout << "Skeleton texture loaded!" << std::endl;

        int xIndex = 0;
        int yIndex = 0;

        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(300, 200));
        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
    }
    else {
        std::cout << "Skeleton texture failed to loaded!" << std::endl;
    }
}

void Skeleton::Update(float deltaTime) {
    for (const auto& [key, movement] : movementMap) {
        if (sf::Keyboard::isKeyPressed(key)) {
            sf::Vector2f position = sprite.getPosition();

            yIndex = movement.yIndex;
            sprite.setPosition(position + movement.vector* skeletonSpeed * deltaTime);
            sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        }
    }

    boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRectangle);
}