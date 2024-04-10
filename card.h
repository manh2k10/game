#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;
enum COLOR {wild, red, green, blue, yellow};

class card
{
    public:
		int number;// 0-9 numbers, +2, skip, reverse, all color, +4 (all color)
		COLOR color; // 5 colors: red, green, blue, yellow, and no color
        SDL_Texture* mycard;


		bool operator==(card const & other) const;

		bool operator!=(card const & other) const;

		card();

		card(int value, COLOR color,SDL_Texture* texture);


};


