#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::Initialize() {
    movementMap = {
        {sf::Keyboard::W, {sf::Vector2f(0, -1),0}}, // up
        {sf::Keyboard::A, {sf::Vector2f(-1, 0),1}}, // left
        {sf::Keyboard::S, {sf::Vector2f(0, 1),2}}, // down
        {sf::Keyboard::D, {sf::Vector2f(1, 0),3}} // right
    };
}

void Player::Load() {
    if (texture.loadFromFile("assets/player/texture/spriteSheet.png")) {
        std::cout << "Player texture loaded!" << std::endl;
        sprite.setTexture(texture);

        int XIndex = 0;
        int YIndex = 0;

        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
        sprite.setPosition(sf::Vector2f(20, 400));
    }
    else {
        std::cout << "Player texture failed to loaded!" << std::endl;
    }
}

void Player::Update(Skeleton& skeleton) {
    for (const auto& [key, movement] : movementMap) {
        if (sf::Keyboard::isKeyPressed(key)) {
            sf::Vector2f position = sprite.getPosition();
            sprite.setPosition(position + movement.vector);
            yIndex = movement.yIndex;
            sprite.setTextureRect(sf::IntRect(64 * xIndex, 64 * yIndex, 64, 64));
        }
    }


    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); i++) {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }
}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);

    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}