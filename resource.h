#pragma once
#include"graphics.h"
class Resource
{
public:

	static SDL_Texture* play;
	static SDL_Texture* background;
	static SDL_Texture* newbackground;//dan

	static SDL_Texture* backcard;
	static SDL_Texture* character;
	static SDL_Texture* choosecolor;

	static void LoadAllData(ultis graphics);
};
