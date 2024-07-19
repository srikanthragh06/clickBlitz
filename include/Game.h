#pragma once

#include <SFML/Graphics.hpp>

namespace game
{
    class Game
    {
    private:
        sf::RenderWindow *window;
        sf::VideoMode videoMode;
        sf::Event windowEvent;

        sf::RectangleShape enemy;

    private:
        void initVariables();
        void initWindow();
        void initEnemies();

        void handleEvents();
        void update();
        void render();

    public:
        Game();
        virtual ~Game();

        void run();
        const bool isRunning() const;
    };
}