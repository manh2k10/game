#pragma once
#include "card.h"
#include "graphics.h"
#include "SDL.h"
#include "SDL_image.h"
#include "player.h"
#include "chucnang.h"
#include "def.h"


    void playturn();
    card choosecard();
    void aibocbai();
    void ainhanbai();
    int choosecolor();
    void playcard();




extern int kcach;
extern int target;
extern bool ncheckboc;
extern bool ncheck;
