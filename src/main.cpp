#include <stdlib.h>
#include <SDL2/SDL.h>
#include "../include/Game.hpp"

Game *game;

int main(int argc, char **argv)
{
    game = new Game();

    game->init("HugyosFos", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, false);

    // Uint32 start = SDL_GetTicks();
    Uint64 last;
    Uint64 now = SDL_GetPerformanceCounter();
    double deltaTime = 0;
    double timepassed = 0;

    while(game->isRunning())
    {

        last = now;
        now = SDL_GetPerformanceCounter();
        timepassed += deltaTime;

        // float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
        // std::cout << "Current FPS: " << std::to_string(1.0f / elapsed) << std::endl;

        deltaTime = double(now - last) * 1000 / (double)SDL_GetPerformanceFrequency();

        game->handleEvents(/*deltaTime, (timepassed >= 10)*/);
        game->update();
        game->render();

        if(timepassed >= 10){
            timepassed = 0;
        }
    }

    game->clean();

    return 0;
}
