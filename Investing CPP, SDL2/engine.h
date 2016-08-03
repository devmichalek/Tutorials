#pragma once
#include "title.h"
#include "goal.h"
#include "currency.h"
#include "attain.h"

class Engine
{
    bool quit;
    int width, height;
    SDL_Event event;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Title title;
    Texture title_bar;

    Goal goal;

    Currency currency;

    Attain attain;

public:

    Engine();
    ~Engine();
    void free();

    bool load();
    bool init();
    void loop();
    void close();
};
