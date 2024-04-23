#pragma once
#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"graphics.h"
#include"card.h"
#include"deck.h"
#include"player.h"
#include"def.h"
#include"resource.h"
extern int targetX ;
extern int disbtw2card;
extern deck main_deck;
extern deck temp_deck;
extern player * play_array;
extern player * curr_play;
extern ultis graphics;
const int targetY = 460;
extern SDL_Event e;
extern card played_card;
extern bool check;
extern bool quit;
void bocbai(int &x,int &y);
void danhbai(int &x,int &y);
void chonmau();
