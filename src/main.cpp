#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

int main()
{

    // window stuff
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "window", sf::Style::Fullscreen);

    // Game loop
    while (renderWindow.isOpen())
    {
        // Event polling0
        sf::Event ev;
        while (renderWindow.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                renderWindow.close();
                break;

            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                {
                    renderWindow.close();
                }
                break;
            }
        }

        // Update

        // Render
        renderWindow.clear(sf::Color::Black); // clear old frame
        // draw your game
        renderWindow.display(); // display whatever is rendered on the window
    }

    return 0;
}
