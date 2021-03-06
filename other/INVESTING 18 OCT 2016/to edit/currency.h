#pragma once
#include "texture.h"
#include "chunk.h"

class Currency
{
	enum
	{
		GBP = 0,
		USD,
		EUR,
		PLN
	};
	
    int nr;
    Texture* texture;

    int picked;

    Chunk click;
    Chunk focus;

public:

    Currency();
    ~Currency();
    void free();

    bool load( SDL_Renderer* &renderer, int title_bar_posY, int screen_width );
    void render( SDL_Renderer* &renderer );
    void handle( SDL_Event &event );

    int get();
};
