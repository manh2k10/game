#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"graphics.h"
#include"card.h"
#include"deck.h"
#include"player.h"
#include"def.h"
using namespace std;

int main(int argc, char* args[])
{
    ultis graphics;
    graphics.SDLInit();
    deck main_deck;
    main_deck.create(graphics);
    main_deck.quick_shuffle();
    player * play_array;
	play_array = new player[2];



    SDL_Texture* background=graphics.loadtexture("images/backgrounds.jpg");
    SDL_Texture* character=graphics.loadtexture("images/bg.png");
    SDL_Texture* play=graphics.loadtexture("images/switch.png");
    SDL_Texture* newbackground=graphics.loadtexture("images/backgrounds3.png");
    SDL_Texture* backcard=graphics.loadtexture("images/back.png");

    SDL_RenderCopy(graphics.renderer,background,NULL,NULL);
    graphics.renderTexture(character,285,95,10,10);
    graphics.renderTexture(play,390,380,7,7);


    SDL_RenderPresent(graphics.renderer);
    int cardX = 300; // Tọa độ X ban đầu của quân bài
    int cardY = 220; // Tọa độ Y ban đầu của quân bài
    int targetX = 550; // Tọa độ X mục tiêu của quân bài
    int targetY = 460; // Tọa độ Y mục tiêu của quân bài
    bool cardDealt = false;
    SDL_Event e;
    bool kt=false,running=true;
    while (running)
    {
      // Uint32 windowID = SDL_GetWindowID(graphics.window);
        while( SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)running=false;
            int x,y;
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                if(e.button.button==SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&x,&y);
                    if(graphics.inside(x,y,graphics.toado(play,320,370)))
                    {
                        kt=true;
                    }
                }
            }
            if (kt && !cardDealt)
            {
                SDL_RenderClear(graphics.renderer);
                SDL_RenderCopy(graphics.renderer,newbackground,NULL,NULL);
                graphics.renderTexture(backcard,300,220,6,6);
                SDL_RenderPresent(graphics.renderer);
                for(int i=0;i<7;i++)
                {

                    main_deck.animateDeal(backcard, newbackground, graphics, 300, 250, targetX, targetY, play_array[0], i+1);
                    card temp_card;
			        temp_card = main_deck.draw();
			        play_array[0].hand_add(temp_card);
                    graphics.renderTexture(temp_card.mycard, targetX, targetY, 6, 6);

                    graphics.renderTexture(backcard, targetX, targetY-420, 6, 6);
                    targetX -= 50;
                    SDL_Delay(10);
                      SDL_RenderPresent(graphics.renderer);
                }
              //  SDL_RenderPresent(graphics.renderer);
                cardDealt=true;


            }

        }
    }
     graphics.free(background);
     graphics.free(backcard);
     graphics.free(play);
     graphics.free(character);
     for(int i=0;i<=108;i++)
        graphics.free(main_deck.ptr_deck[i].mycard);
    graphics.close();
    return 0;
}
