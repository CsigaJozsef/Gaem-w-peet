#include "../include/Game.hpp"

Game::Game()
{
    player = new Player();
    // xMouse = 0;
    // yMouse = 0;
}

Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL Initialized..." << std::endl;

        _window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (_window)
        {
            std::cout << "Windows created" << std::endl;
        }

        _renderer = SDL_CreateRenderer(_window, -1, 0);
        // _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED );

        if (_renderer)
        {
            SDL_SetRenderDrawColor(_renderer, 173, 216, 230, 255);
            std::cout << "Renderer created" << std::endl;
        }

        _running = true;

        _height = height;
        _width = width;
    }
    else
    {
        _running = false;
    }
}

void Game::handleEvents(/*double delta, bool refreshKBDState*/)
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        // Closing window
        case SDL_QUIT:
            _running = false;
            break;

        default:
            break;
    }

    // if(event.type == SDL_MOUSEMOTION)
    // {
    //     SDL_GetMouseState(&xMouse,&yMouse);
    //     std::cout<< "mouse:" << xMouse << ", " << yMouse << std::endl;
    // }

    // if (refreshKBDState)
    // {
    //     const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    //     if (keystates[SDL_SCANCODE_W])
    //     {
    //         player->move(UP, delta);
    //     }

    //     if (keystates[SDL_SCANCODE_S])
    //     {
    //         player->move(DOWN, delta);
    //     }

    //     if (keystates[SDL_SCANCODE_A])
    //     {
    //         player->move(LEFT, delta);
    //     }

    //     if (keystates[SDL_SCANCODE_D])
    //     {
    //         player->move(RIGHT, delta);
    //     }
    // }


}

void Game::update()
{
}

void Game::render()
{
    SDL_SetRenderDrawColor(_renderer, 173, 216, 230, 255);
    SDL_RenderClear(_renderer);

    SDL_Rect rect;
    rect.x = player->getX();
    rect.y = player->getY();
    rect.w = 20;
    rect.h = 20;

    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(_renderer, &rect);

    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
    // SDL_RenderDrawLine(_renderer, player->getX() + 10, player->getY() + 10, xMouse, yMouse);

    SDL_RenderPresent(_renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

bool Game::isRunning()
{
    return _running ? true : false;
}