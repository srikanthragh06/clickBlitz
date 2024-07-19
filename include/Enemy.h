#pragma once

#include <SFML/Graphics.hpp>

namespace game
{
    class Enemy
    {
    public:
        sf::CircleShape enemyCircle;
        float enemySpeed;
        float enemyRadiusScale;

        Enemy(sf::RenderWindow &window);

        ~Enemy();
    };
}