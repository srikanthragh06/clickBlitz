#include <iostream>

#include "Game.h"

namespace game
{
    void Game::initVariables()
    {
        this->window = nullptr;
    }
    void Game::initWindow()
    {
        this->videoMode.width = 800;
        this->videoMode.height = 600;

        this->window = new sf::RenderWindow(this->videoMode, "My Window", sf::Style::Titlebar | sf::Style::Close);

        this->window->setFramerateLimit(60);
    }

    void Game::initEnemies()
    {
        this->enemy.setPosition(10.f, 10.f);
        this->enemy.setSize(sf::Vector2f(100.f, 100.f));
        this->enemy.setScale(0.5f, 0.5f);
        this->enemy.setFillColor(sf::Color::Magenta);
        this->enemy.setOutlineColor(sf::Color::Red);
        this->enemy.setOutlineThickness(1.f);
    }

    Game::Game()
    {
        this->initVariables();
        this->initWindow();
        this->initEnemies();
    }

    Game::~Game()
    {
        delete this->window;
    }

    void Game::run()
    {
        while (this->isRunning())
        {
            this->update();
            this->render();
        }
    }

    const bool Game::isRunning() const
    {
        return this->window->isOpen();
    }

    void Game::update()
    {
        this->handleEvents();

        std::cout << "Mouse position: " << sf::Mouse::getPosition(*this->window).x << ", " << sf::Mouse::getPosition(*this->window).y << std::endl;
    }

    void Game::render()
    {

        this->window->clear();

        this->window->draw(this->enemy);

        this->window->display();
    }

    void Game::handleEvents()
    {
        while (this->window->pollEvent(this->windowEvent))
        {
            switch (this->windowEvent.type)
            {

            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:

                switch (this->windowEvent.key.code)
                {
                case sf::Keyboard::Escape:
                    this->window->close();
                    break;
                }
            }
        }
    }

}