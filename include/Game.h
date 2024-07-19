#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

namespace game
{
    class Game
    {
    private:
        sf::RenderWindow *window;
        sf::VideoMode videoMode;
        sf::Event windowEvent;

        sf::Vector2i mousePosWindow;

        sf::CircleShape enemy;
        std::vector<sf::CircleShape> enemies;

        // game logic members
        int points;
        float enemySpawnTimer;
        float enemySpawnTimerMax;
        unsigned int maxEnemies;

    private:
        void initVariables();
        void initWindow();
        void initEnemies();

        void update();

        void updateEvents();
        void updateMousePos();
        void updateEnemies();

        void render();

        void renderEnemies();

        void spawnEnemy();

    public:
        Game();
        virtual ~Game();

        void run();
        const bool isRunning() const;
    };
}