#pragma once
#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"graphics.h"
#include"card.h"
#include"deck.h"
#include"player.h"
#include"def.h"

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
