#include "menuCharacter.h"
#include <iostream>


void Character::Initialize() {
    sprite.scale(sf::Vector2f(scale, scale));
}

void Character::Load() {
    if (texture.loadFromFile("assets/character/texture/spriteSheet.png")) {
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(300, 500));
        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        std::cout << "Character texture loaded!" << std::endl;
    }
    else {
        std::cout << "Character texture failed to loaded!" << std::endl;
    }
}

void Character::Update(sf::RenderWindow& window) {
    elapsedTime += animationSpeed;
    if (elapsedTime >= 0.18f) {
        elapsedTime = 0.0f;
        xIndex++;
        if (xIndex * size.x >= texture.getSize().x) {
            xIndex = 0;
        }
        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
    }
    if (int(xCharacter) >= int(window.getSize().x)) {
        yIndex = 1;
        direction = -1;
    }
    if (xCharacter <= 0 - size.x * scale) {
        yIndex = 2;
        direction = 1;
    }
    xCharacter += direction * 5;
    sprite.setPosition(sf::Vector2f(xCharacter, window.getSize().y - sprite.getGlobalBounds().height));
}

void Character::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
