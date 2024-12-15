#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize() {
    movementMap = {
        {sf::Keyboard::I, {sf::Vector2f(0, -1),0}}, // up
        {sf::Keyboard::J, {sf::Vector2f(-1, 0),1}}, // left
        {sf::Keyboard::K, {sf::Vector2f(0, 1),2}}, // down
        {sf::Keyboard::L, {sf::Vector2f(1, 0),3}} // right
    };
}

void Skeleton::Load() {
    if (texture.loadFromFile("assets/skeleton/texture/spriteSheet.png")) {
        std::cout << "Skeleton texture loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(300, 200));

        int XIndex = 0;
        int YIndex = 2;

        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
    }
    else {
        std::cout << "Skeleton texture failed to loaded!" << std::endl;
    }
}

void Skeleton::Update() {
    for (const auto& [key, movement] : movementMap) {
        if (sf::Keyboard::isKeyPressed(key)) {
            sf::Vector2f position = sprite.getPosition();
            sprite.setPosition(position + movement.vector);
            yIndex = movement.yIndex;
        }
    }
    sprite.setTextureRect(sf::IntRect(64 * xIndex, 64 * yIndex, 64, 64));
}

void Skeleton::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}