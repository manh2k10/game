#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"graphics.h"
#include"card.h"
#include"deck.h"
using namespace std;

const int RECT=5;


int main(int argc, char* args[])
{
    ultis graphics;

    graphics.SDLInit();
    card tmp;
   deck main_deck;
     main_deck.create(graphics);
    SDL_Texture* background=graphics.loadtexture("images/backgrounds.jpg");
    SDL_RenderCopy(graphics.renderer,background,NULL,NULL);

    SDL_Texture* character=graphics.loadtexture("images/bg.png");
    graphics.renderTexture(character,205,95,10,10);

    SDL_Texture* play=graphics.loadtexture("images/switch.png");
    graphics.renderTexture(play,320,370,7,7);

    SDL_RenderPresent(graphics.renderer);
    SDL_Event e;
    while (true)
        {
           if ( SDL_PollEvent(&e) != 0)
           {
               if(e.type == SDL_QUIT) break;
               int x,y;
               if(e.type==SDL_MOUSEBUTTONDOWN)
               {
                    if(e.button.button==SDL_BUTTON_LEFT)
                     {
                         SDL_GetMouseState(&x,&y);
                         if(graphics.inside(x,y,graphics.toado(play,320,370)))
                         {

                             SDL_Texture* newbackground=graphics.loadtexture("images/backgrounds3.png");
                             SDL_RenderCopy(graphics.renderer,newbackground,NULL,NULL);

                              SDL_RenderPresent(graphics.renderer);

                                SDL_RenderPresent(graphics.renderer);
                         }


                     }
               }
           }
          // SDL_Delay(10);
        }



    graphics.close();
    return 0;
}
