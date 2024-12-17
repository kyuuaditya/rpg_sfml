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

    // set the scale size.
    size = sf::Vector2i(64, 64);
    sprite.scale(sf::Vector2f(3, 3));

    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);
    boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

void Player::Load() {
    if (texture.loadFromFile("assets/player/texture/spriteSheet.png")) {
        std::cout << "Player texture loaded!" << std::endl;
        sprite.setTexture(texture);

        int xIndex = 0;
        int yIndex = 0;

        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));

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
            sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
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
    boundingRectangle.setPosition(sprite.getPosition());

    if (Math::DidRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
        boundingRectangle.setOutlineColor(sf::Color::Cyan);
        skeleton.boundingRectangle.setOutlineColor(sf::Color::Red);
    }
    else {
        boundingRectangle.setOutlineColor(sf::Color::Red);
        skeleton.boundingRectangle.setOutlineColor(sf::Color::Cyan);
    };
}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRectangle);

    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}