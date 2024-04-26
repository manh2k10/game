#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"graphics.h"
#include"card.h"
#include"deck.h"
#include"player.h"
#include"def.h"
#include"game.h"
using namespace std;

int main(int argc, char* args[])
{
   Game::GetInstance()->Run();
    return 0;
}
