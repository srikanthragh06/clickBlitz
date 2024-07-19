#include <ctime>

#include "Game.h"

int main()
{
    std::srand(std::time(0));

    game::Game game;
    game.run();

    return 0;
}
