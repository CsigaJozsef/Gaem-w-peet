#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "Player.hpp"
#include "Directions.hpp"

class Game 
{
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents(/*double delta, bool refreshKBDState*/);
    void update();
    void render();
    void clean();

    bool isRunning();

    Player* player;

private:
    int _width;
    int _height;
    // int xMouse, yMouse;
    bool _running;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
};