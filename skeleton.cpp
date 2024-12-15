#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize() {
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
}

void Skeleton::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

// #include "skeleton.h"
// #include <iostream>



// void Skeleton::Initialize1() {
//     movementMap2 = {
//         {sf::Keyboard::I, {sf::Vector2f(0, -1),0}}, // up
//         {sf::Keyboard::J, {sf::Vector2f(-1, 0),1}}, // left
//         {sf::Keyboard::K, {sf::Vector2f(0, 1),2}}, // down
//         {sf::Keyboard::L, {sf::Vector2f(1, 0),3}} // right
//     };
// }

// void Skeleton::Load1() {
//     if (stexture.loadFromFile("assets/skeleton/texture/spriteSheet.png")) {
//         ssprite.setTexture(stexture);
//         ssprite.setPosition(sf::Vector2f(600, 200));
//         ssprite.setTextureRect(sf::IntRect(64 * xeIndex, 64 * yeIndex, 64, 64));
//         ssprite.scale(sf::Vector2f(2, 2));
//         std::cout << "skeleton texure loaded" << std::endl;
//     }
//     else {
//         std::cout << "Error loading skeleton texture" << std::endl;
//     }
// }

// void Skeleton::Update1() {
//     for (const auto& [key, movement] : movementMap2) {
//         if (sf::Keyboard::isKeyPressed(key)) {
//             sf::Vector2f position = ssprite.getPosition();
//             ssprite.setPosition(position + movement.vector);
//             yeIndex = movement.yIndex;
//         }
//     }
//     ssprite.setTextureRect(sf::IntRect(64 * xeIndex, 64 * yeIndex, 64, 64));
//     // sf::Vector2f position = sprite.getPosition();
//     // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//     //     sprite.setPosition(position + sf::Vector2f(0, -1));
//     // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//     //     sprite.setPosition(position + sf::Vector2f(-1, 0));
//     // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//     //     sprite.setPosition(position + sf::Vector2f(0, 1));
//     // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//     //     sprite.setPosition(position + sf::Vector2f(1, 0));
// }

// void Skeleton::Draw1(sf::RenderWindow& window) {
//     window.draw(ssprite);
//     // std::cout << "a";
// }

// sf::Sprite& Skeleton::getSprite() {
//     return ssprite;
// }