#include <ctime>

#include "Game.h"
#include "Enemy.h"
namespace game
{
    void Game::initVariables()
    {
        this->window = nullptr;

        // game logic
        this->points = 0;
        this->health = 3;
        this->enemySpawnTimerMax = 35.f;
        this->enemySpawnTimer = this->enemySpawnTimerMax;
        this->enemySpeedMult = 1.f;
        this->maxEnemies = 10;
        this->mouseHeld = false;
        this->mouseClick = false;
    }
    void Game::initWindow()
    {
        this->videoMode.width = 800;
        this->videoMode.height = 600;

        this->window = new sf::RenderWindow(this->videoMode, "Click Blitz", sf::Style::Titlebar | sf::Style::Close);

        this->window->setFramerateLimit(60);
    }

    void Game::initFonts()
    {
        if (!this->font.loadFromFile("fonts/ShareTechMono-Regular.ttf"))
        {
            std::cout << "Failed to load font!" << std::endl;
        }
    }

    void Game::initText()
    {
        this->UIText.setFont(this->font);
        this->UIText.setCharacterSize(24);
        this->UIText.setFillColor(sf::Color::White);
        this->UIText.setString("NONE");
    }

    Game::Game()
    {
        this->initVariables();

        this->initWindow();

        this->initFonts();
        this->initText();
    }

    Game::~Game()
    {
        delete this->window;
    }

    void Game::run()
    {
        while (this->isRunning() && !this->getEndGame())
        {
            this->update();
            this->render();
        }
    }

    const bool Game::isRunning() const
    {
        return this->window->isOpen();
    }

    const bool Game::getEndGame() const
    {
        return this->endGame;
    }

    void Game::update()
    {
        this->updateEvents();

        this->updateMousePos();
        this->updateMouseClick();
        this->updateText();

        if (!this->endGame)
        {
            this->updateEnemies();
        }

        // end game condition
        if (this->health <= 0)
        {
            this->endGame = true;
        }
    }

    void Game::updateMousePos()
    {
        this->mousePosWindow = sf::Mouse::getPosition(*this->window);
        this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
    }

    void Game::updateMouseClick()
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (this->mouseClick)
            {
                this->mouseHeld = true;
            }
            this->mouseClick = true;
        }
        else
        {
            this->mouseHeld = false;
            this->mouseClick = false;
        }
    }

    void Game::updateText()
    {
        std::stringstream ss;

        ss << "Points: " << this->points << "\n"
           << "Health: " << this->health;

        this->UIText.setString(ss.str());
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

                this->enemySpeedMult += 0.025f;
            }
            else
            {
                this->enemySpawnTimer += 1.f;
            }
        }

        // Enemy movement and removal
        for (int i = 0; i < this->enemies.size(); i++)
        {
            // move enemy
            this->enemies[i].enemyCircle.move(0.f, this->enemySpeedMult * enemies[i].enemySpeed);

            // enemy deletion if they go below the screen
            if (this->enemies[i].enemyCircle.getPosition().y > this->window->getSize().y)
            {
                this->enemies.erase(this->enemies.begin() + i);
                this->health -= 1;
            }
        }

        // Killing enemies
        if (this->mouseClick && !this->mouseHeld)
        {
            bool deleted = false;

            for (int i = 0; i < this->enemies.size() && !deleted; i++)
            {
                if (this->enemies[i].enemyCircle.getGlobalBounds().contains(this->mousePosView))
                {
                    this->points += static_cast<int>((10 / enemies[i].enemyRadiusScale) + (15 * enemies[i].enemySpeed * this->enemySpeedMult));

                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);
                }
            }
        }
    }

    void Game::render()
    {

        this->window->clear();

        this->renderEnemies(*this->window);

        this->renderText(*this->window);

        this->window->display();
    }

    void Game::renderEnemies(sf::RenderTarget &target)
    {
        for (auto &e : this->enemies)
        {
            target.draw(e.enemyCircle);
        }
    }

    void Game::renderText(sf::RenderTarget &target)
    {
        target.draw(this->UIText);
    }

    void Game::spawnEnemy()
    {
        Enemy newEnemy(*this->window);
        this->enemies.push_back(newEnemy);
    }

}