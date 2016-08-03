#include "title.h"

Title::~Title()
{
    free();
}

void Title::free()
{
    texture.free();
    font.free();
}

bool Title::load( SDL_Renderer* &renderer, int screen_width )
{
    bool success = true;

    free();

    if( !font.load( "data/ShadedLarch_PERSONAL_USE.ttf", 50 ) )
    {
        success = false;
    }
    else
    {
        SDL_Color color = { 0xFF, 0xFF, 0xFF };
        if( !texture.loadFromRenderedText( renderer, font.get(), "investing", color ) )
        {
            success = false;
        }
        else
        {
            texture.getX() = ( screen_width/2 ) - ( texture.getW()/2 );
            texture.getY() = 0;

            texture.setColor( 0x09, 0x70, 0x54 );
        }
    }


    return success;
}

void Title::render( SDL_Renderer* &renderer )
{
    texture.render( renderer );
}

int &Title::getW()
{
    return texture.getW();
}

int &Title::getH()
{
    return texture.getH();
}
