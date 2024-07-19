#pragma once
#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

#include "Enemy.h"

namespace game
{
    class Game
    {
    private:
        sf::RenderWindow *window;
        sf::VideoMode videoMode;
        sf::Event windowEvent;

        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        std::vector<Enemy> enemies;

        // game logic members
        bool endGame = false;
        unsigned int points;
        int health;
        float enemySpawnTimer;
        float enemySpawnTimerMax;
        float enemySpeedMult;
        unsigned int maxEnemies;
        bool mouseHeld;
        bool mouseClick;

        // resources
        sf::Font font;

        // text
        sf::Text UIText;

    private:
        void initVariables();
        void initWindow();
        void initEnemies();
        void initText();
        void initFonts();

        void update();

        void updateEvents();
        void updateMousePos();
        void updateMouseClick();
        void updateText();
        void updateEnemies();

        void render();

        void renderEnemies(sf::RenderTarget &target);
        void renderText(sf::RenderTarget &target);

        void spawnEnemy();

    public:
        Game();
        virtual ~Game();

        void run();
        const bool isRunning() const;
        const bool getEndGame() const;
    };
}