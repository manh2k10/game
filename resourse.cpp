#include "resource.h"

SDL_Texture* Resource::play;
SDL_Texture* Resource::backcard;
SDL_Texture* Resource::background;

SDL_Texture* Resource::character;
SDL_Texture* Resource::choosecolor;
SDL_Texture* Resource::newbackground;

SDL_Texture* Resource::cred;
SDL_Texture* Resource::cgreen;
SDL_Texture* Resource::cblue;
SDL_Texture* Resource::cyellow;


void Resource::LoadAllData(ultis graphics)
{
    background = graphics.loadtexture("images/backgrounds.jpg");
    character = graphics.loadtexture("images/bg.png");
    play = graphics.loadtexture("images/switch.png");
    newbackground = graphics.loadtexture("images/backgrounds3.png");
    backcard = graphics.loadtexture("images/back.png");
    choosecolor = graphics.loadtexture("images/choosecolor.png");
    cred = graphics.loadtexture("images/red.png");
    cblue = graphics.loadtexture("images/blue.png");
    cgreen = graphics.loadtexture("images/green.png");
    cyellow = graphics.loadtexture("images/yellow.png");

}

