#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "sdl_ultis.h"
#include<string>
enum COLOR {wild, red, green, blue, yellow};

class card
{
    public:
		int number; // 0-9 numbers, +2, skip, reverse, all color, +4 (all color)
		COLOR color; // 5 colors: red, green, blue, yellow, and no color

		bool operator==(card const & other) const;

		bool operator!=(card const & other) const;

		card();

		card(int value, COLOR color, SDL_Texture* texture,SDL_Renderer*renderer);


		SDL_Texture* mycard;
		SDL_Renderer*myrender;
};
vector <card>allcard;
void createcard();

#endif

