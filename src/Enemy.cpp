#include "Enemy.h"
#include "utils.h"

namespace game
{
    Enemy::Enemy(sf::RenderWindow &window)
    {
        this->enemySpeed = generateRandomFloat(1, 2);
        this->enemyRadiusScale = generateRandomFloat(0.5, 1.25);

        this->enemyCircle.setRadius(35.f * this->enemyRadiusScale);
        this->enemyCircle.setPosition(generateRandomFloat(0, window.getSize().x - this->enemyCircle.getRadius() * 2), -20.f);
        this->enemyCircle.setScale(1.f, 1.f);
        this->enemyCircle.setFillColor(sf::Color::White);
        this->enemyCircle.setOutlineColor(sf::Color::White);
        this->enemyCircle.setOutlineThickness(1.f);
    }

    Enemy::~Enemy()
    {
    }
}
