#include <ctime>

#include "Game.h"

namespace game
{
    void Game::initVariables()
    {
        this->window = nullptr;

        // game logic
        this->points = 0;
        this->enemySpawnTimerMax = 1000.f;
        this->enemySpawnTimer = this->enemySpawnTimerMax;
        this->maxEnemies = 10;
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
        this->enemy.setRadius(50.f);
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
        this->updateEvents();
        this->updateMousePos();
        this->updateEnemies();
    }

    void Game::updateMousePos()
    {
        this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    }

    void Game::updateEvents()
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
    void Game::updateEnemies()
    {
        // Enemy generation
        if (this->enemies.size() < this->maxEnemies)
        {

            if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
            {
                this->spawnEnemy();
                this->enemySpawnTimer = 0.f;
            }
            else
            {
                this->enemySpawnTimer += 30.f;
            }
        }

        // Move the enemies
        for (auto &enemy : this->enemies)
        {
            enemy.move(0.f, 5.f);
        }
    }

    void Game::render()
    {

        this->window->clear();

        this->renderEnemies();

        this->window->display();
    }

    void Game::renderEnemies()
    {
        for (auto &e : this->enemies)
        {
            this->window->draw(e);
        }
    }

    void Game::spawnEnemy()
    {
        this->enemy.setPosition(
            static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getRadius() * 2)),
            -5);

        this->enemy.setFillColor(sf::Color::White);

        this->enemies.push_back(this->enemy);
    }

}