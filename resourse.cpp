#include "resource.h"

SDL_Texture* Resource::play;
SDL_Texture* Resource::backcard;
SDL_Texture* Resource::background;
SDL_Texture* Resource::exit;
SDL_Texture* Resource::playagain;

SDL_Texture* Resource::character;
SDL_Texture* Resource::choosecolor;
SDL_Texture* Resource::newbackground;

SDL_Texture* Resource::cred;
SDL_Texture* Resource::cgreen;
SDL_Texture* Resource::cblue;
SDL_Texture* Resource::cyellow;

SDL_Texture* Resource::youwin;
SDL_Texture* Resource::youlose;

Mix_Chunk* Resource::loser ;
Mix_Chunk* Resource::winner;
Mix_Chunk* Resource::colorbutton;
Mix_Chunk* Resource::playgame;
Mix_Chunk* Resource::drawcard;
Mix_Music* Resource::nhacnen;


void Resource::LoadAllData(ultis graphics)
{
    background = graphics.loadtexture("images/backgrounds.jpg");
    character = graphics.loadtexture("images/bg.png");
    play = graphics.loadtexture("images/newplay.png");
    exit = graphics.loadtexture("images/EXIT.png");
    playagain = graphics.loadtexture("images/playagain.png");


    newbackground = graphics.loadtexture("images/backgrounds3.png");
    backcard = graphics.loadtexture("images/back.png");
    choosecolor = graphics.loadtexture("images/choosecolor.png");

    cred = graphics.loadtexture("images/red.png");
    cblue = graphics.loadtexture("images/blue.png");
    cgreen = graphics.loadtexture("images/green.png");
    cyellow = graphics.loadtexture("images/yellow.png");

    youwin= graphics.loadtexture("images/uno!.png");
    youlose= graphics.loadtexture("images/youlose.png");

    loser=Mix_LoadWAV( "audio/lose.wav" );
    winner=Mix_LoadWAV( "audio/mywin.wav" );
    drawcard=Mix_LoadWAV( "audio/playCard1.wav" );

    playgame=Mix_LoadWAV( "audio/playCard2.wav" );
    colorbutton=Mix_LoadWAV( "audio/colorButton.wav" );
    nhacnen=Mix_LoadMUS( "audio/nhacnen.mp3" );


}

