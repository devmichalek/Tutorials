#include "profit.h"
#include <stdio.h>

void Profit::sortString()
{
    for( unsigned i = 0; i < inputText.length(); i ++ )
    {
        if( inputText[ i ] == ' ' )
        {
            inputText.erase( i, 1 );
        }
    }

    string newInputText = "";
    int c = inputText.length()-1;
    for( unsigned i = 0; i < inputText.length(); i ++ )
    {
        newInputText += inputText[ i ];

        if( c%3 == 0 )
        {
            newInputText += ' ';
        }

        c --;
    }
    inputText = newInputText;
}

// Only +numbers
long long Profit::strToInt( string s )
{
    long long tmp = 0;

    for( unsigned i = 0; i < s.size(); i++ )
    {
        if( s[ i ] == ' ' )
            continue;

        tmp = 10 * tmp + s[ i ] - 48;
    }

    return tmp;
}

Profit::Profit( char c, int x, int y )
{
	texture = NULL;
	name = "";
	renderText = false;
	cost = 0;
	inputText = "";
	
	focus_n = focus_v = false;
	focus_w_v = focus_w_n = 0;
	
	this->c = c;
	nr = 0;
	
	this->x = x;
	this->y = y;
	
	thrash = false;
}

Profit::~Profit()
{
	free();
}

void Profit::free()
{
	font.free();
	
	if( texture != NULL )
	{
		for( int i = 0; i < nr; i ++ )
		{
			texture[ i ].free();
		}
		
		delete [] texture;
		texture = NULL;
		nr = 0;
	}
	
	name = "";
	renderText = false;
	cost = 0;
	inputText = "";
	
	nr = 0;
}

	
bool Profit::load( SDL_Renderer* &renderer, SDL_Window* &window )
{
	register bool success = true;
	
	free();
	
	if( !font.load( "data/ShadedLarch_PERSONAL_USE.ttf", 25 ) )
	{
		success = false;
	}
	
	nr = 7;
	texture = new Texture [ nr ];
	if( texture != NULL && success )
	{
		int sw, sh;
		SDL_GetWindowSize( window, &sw, &sh );
		
		if( c == 'c' )
		{
			color.r = 0xE8;
			color.g = 0x68;
			color.b = 0x50;
			printf( "2222cps" );
		}
		else
		{
			color.r = 0x58;
			color.g = 0x70;
			color.b = 0x58;
			printf( "cps" );
		}
		
		int bar_h = 20;
		if( !texture[ 0 ].createWithColor( renderer, color.r, color.g, color.b, sw, bar_h ) )
		{
			success = false;
		}
		else
		{
			texture[ 0 ].getX() = x;
			texture[ 0 ].getY() = y;
		}
		
		
		if( !texture[ 1 ].loadFromFile( renderer, window, "data/thrash.png" ) )
		{
			success = false;
		}
		else
		{
			texture[ 1 ].getH() = texture[ 1 ].getH()/2.7;
			texture[ 1 ].getW() = texture[ 1 ].getW()/2.5;
			
			texture[ 1 ].getX() = sw - texture[ 1 ].getW()-5;
			texture[ 1 ].getY() = y + bar_h - texture[ 1 ].getH()-1;
		}
		
		if( !texture[ 2 ].loadFromFile( renderer, window, "data/money.png" ) )
		{
			success = false;
		}
		else
		{
			texture[ 2 ].getH() = texture[ 2 ].getH()/2.7;
			texture[ 2 ].getW() = texture[ 2 ].getW()/2.5;
			
			texture[ 2 ].getX() = texture[ 1 ].getX() - 8 - texture[ 2 ].getW();
			texture[ 2 ].getY() = texture[ 1 ].getY() + 2;
		}
		
		if( !texture[ 3 ].loadFromFile( renderer, window, "data/calendar.png" ) )
		{
			success = false;
		}
		else
		{
			texture[ 3 ].getH() = texture[ 3 ].getH()/2.7;
			texture[ 3 ].getW() = texture[ 3 ].getW()/2.5;
			
			texture[ 3 ].getX() = texture[ 2 ].getX() - 8 - texture[ 3 ].getW();
			texture[ 3 ].getY() = texture[ 1 ].getY();
		}
		
		int focus_width = 100;
		color.r = 0xFF;
		color.g = 0xFF;
		color.b = 0xFF;
		if( !texture[ 4 ].loadFromRenderedText( renderer, font.get(), "value: ", color ) )
		{
			success = false;
		}
		else
		{
			texture[ 4 ].getX() = x + 5;
			texture[ 4 ].getY() = y-2;
			focus_w_v = texture[ 4 ].getW() + focus_width;
		}
		
		if( !texture[ 5 ].loadFromRenderedText( renderer, font.get(), "name: ", color ) )
		{
			success = false;
		}
		else
		{
			texture[ 5 ].getX() = sw/2 - texture[ 5 ].getW()/2-15;
			texture[ 5 ].getY() = y-2;
			focus_w_n = texture[ 5 ].getW() + focus_width;
		}
	}
	
	return success;
}

void Profit::render( SDL_Renderer* &renderer )
{
	for( int i = 0; i < nr; i++ )
	{
		texture[ i ].render( renderer );
	}
}

bool Profit::isThrash()
{
	return thrash;
}

