#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"sdl_ultis.h"
#include"card.h"
using namespace std;

vector <card> allcard;
card CARD;
const int width=800;
const int height=600;
const string title="uno!!";
const int RECT=5;


int main(int argc, char* args[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDLInit(window, renderer,width,height,title);

    CARD.createcard(allcard,renderer);

    SDL_Texture* background=loadtexture("images/backgrounds.jpg",renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);

    SDL_Texture* character=loadtexture("images/bg.png",renderer);
    SDL_Rect charrect;
    SDL_QueryTexture(character,NULL,NULL,&charrect.w,&charrect.h);
    charrect.x=205;
    charrect.y=95;
    charrect.w= charrect.w/10;
    charrect.h= charrect.h/10;
    SDL_RenderCopy(renderer,character,NULL,&charrect);


    SDL_Texture* play=loadtexture("images/switch.png",renderer);
    SDL_Rect playrect;
    SDL_QueryTexture(play,NULL,NULL,&playrect.w,&playrect.h);
    playrect.x=320;
    playrect.y=370;
    playrect.w= playrect.w/7;
    playrect.h= playrect.h/7;

    SDL_RenderCopy(renderer,play,NULL,&playrect);

    SDL_RenderPresent(renderer);
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
                         cout<<"left"<<endl;
                         SDL_GetMouseState(&x,&y);
                         cout<<x<<' '<<y<<endl;
                         if(inside(x,y,playrect))
                         {
                             SDL_Texture* newbackground=loadtexture("images/backgrounds3.png",renderer);
                             SDL_RenderCopy(renderer,newbackground,NULL,NULL);
;
                              SDL_RenderPresent(renderer);
                         }


                     }
               }
           }
           SDL_Delay(100);
        }



    close(window,renderer);
    return 0;
}
