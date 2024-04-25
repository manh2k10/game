#pragma once
#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"graphics.h"
#include"card.h"
#include"deck.h"
#include"player.h"
#include"def.h"
#include"aiplayer.h"
#include <SDL_mixer.h>
class Resource
{
public:

	static SDL_Texture* play;
	static SDL_Texture* background;
	static SDL_Texture* newbackground;//dan

	static SDL_Texture* backcard;
	static SDL_Texture* character;
	static SDL_Texture* choosecolor;

    static SDL_Texture* cred;
	static SDL_Texture* cgreen;
	static SDL_Texture* cblue;
	static SDL_Texture* cyellow;
	static SDL_Texture* youwin;
	static SDL_Texture* youlose;

	static Mix_Chunk* loser ;
    static Mix_Chunk* winner;
    static Mix_Chunk* colorbutton;

    static Mix_Chunk* playgame;
    static Mix_Chunk* drawcard;
    static Mix_Music* nhacnen;



	static void LoadAllData(ultis graphics);
};


