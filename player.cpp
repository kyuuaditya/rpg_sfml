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

    size = sf::Vector2i(64, 64); // size fo the skeleton sprite
    sprite.scale(sf::Vector2f(3, 3)); // scale of the skeleton sprite

    // bounding rectangle properties
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);
    boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

void Player::Load() { // load player texture
    if (texture.loadFromFile("assets/player/texture/spriteSheet.png")) {
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(20, 400));
        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        std::cout << "Player texture loaded!" << std::endl;
    }
    else {
        std::cout << "Player texture failed to loaded!" << std::endl;
    }
}

void Player::Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition) {
    // update player position and sprite
    for (const auto& [key, movement] : movementMap) {
        if (sf::Keyboard::isKeyPressed(key)) {
            sf::Vector2f position = sprite.getPosition();

            yIndex = movement.yIndex;
            sprite.setPosition(position + movement.vector * playerSpeed * deltaTime);
            sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        }
    }

    boundingRectangle.setPosition(sprite.getPosition()); // copy player position to the bounding rectangle

    fireRateTimer += deltaTime; // update fire rate timer

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) { // ckeck bullet shooting
        bullets.push_back(Bullet());
        int i = bullets.size() - 1;
        bullets[i].Initialize(sprite.getPosition(), mousePosition, 0.5f);
        fireRateTimer = 0;
    }

    for (size_t i = 0; i < bullets.size(); i++) { // update bullet positions
        bullets[i].Update(deltaTime);

        // check bullet collision with skeleton
        if (Math::DidRectCollide(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
            bullets.erase(bullets.begin() + i);
            skeleton.health -= 5;
            skeleton.stats.setString("Health: " + std::to_string(skeleton.health));
        };
    }

    // check player collision with skeleton
    if (Math::DidRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds())) { // change colors on collision
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

    for (size_t i = 0; i < bullets.size(); i++) { // draw bullets
        bullets[i].Draw(window);
    }
}