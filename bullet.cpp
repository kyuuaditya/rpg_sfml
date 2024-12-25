#include "bullet.h"
#include <math.h>
#include "Math.h"

void Bullet::Initialize(const sf::Vector2f& position, sf::Vector2f& target, float speed) { // initialize bullet
    this->speed = speed;
    rectangleShape.setSize(sf::Vector2f(20, 10));
    rectangleShape.setPosition(position);
    direction = Math::NormalizeVector(target - position);
}

void Bullet::Update(float deltaTime) {
    rectangleShape.setPosition(rectangleShape.getPosition() + direction * speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow& window) {
    window.draw(rectangleShape);
}
