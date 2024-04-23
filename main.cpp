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
    SDL_Texture* choosecolor=graphics.loadtexture("images/choosecolor.png");
    SDL_RenderCopy(graphics.renderer,background,NULL,NULL);
    graphics.renderTexture(character,285,95,10,10);
    graphics.renderTexture(play,390,430,6,6);


    SDL_RenderPresent(graphics.renderer);
    int disbtw2card;
    if(play_array[0].get_size() > mxwid/wcard)
           disbtw2card=mxwid/play_array[0].get_size();
    else
          disbtw2card=wcard;

    int targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2;// Tọa độ X mục tiêu của quân bài


    int targetY = 460; // Tọa độ Y mục tiêu của quân bài
    bool cardDealt = false;
    SDL_Event e;
    bool kt=false,running=true;
    while (running)
    {
      // Uint32 windowID = SDL_GetWindowID(graphics.window);
        if( SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)running=false;
            int x,y;
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                if(e.button.button==SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&x,&y);
                    cout<<x<<' '<<y<<endl;
                    if(graphics.inside(x,y,graphics.toado(play,390,430,6,6)))
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

                    main_deck.animateDeal(backcard,backcard, newbackground, graphics, 300, 250, targetX, targetY, play_array);
                    card temp_card;
			        temp_card = main_deck.draw();
			        temp_card.toadox=targetX;
			        temp_card.toadoy=targetY;
			        play_array[0].hand_add(temp_card);
			        cout<<play_array[0].get_size();
                    graphics.renderTexture(temp_card.mycard, targetX, targetY, 6, 6);
                    main_deck.animateDeal(backcard,backcard, newbackground, graphics, 300, 250, targetX, targetY-420, play_array);
                    temp_card = main_deck.draw();
			        play_array[1].hand_add(temp_card);
                    graphics.renderTexture(backcard, targetX, targetY-420, 6, 6);
                     if(play_array[0].get_size() > mxwid/wcard)
                        disbtw2card=mxwid/play_array[0].get_size();
                     else
                         disbtw2card=wcard;
                    targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2-(play_array[0].get_size())*disbtw2card;
                    SDL_Delay(10);
                      SDL_RenderPresent(graphics.renderer);
                }
              //  SDL_RenderPresent(graphics.renderer);
                cardDealt=true;
                deck temp_deck;
            card played_card;
            card temp_card;
	        int card_flag = 0 ;
	        while (card_flag == 0 )
            {
                    temp_card = main_deck.draw();
                    main_deck.animateDeal(backcard,backcard, newbackground, graphics, 300, 250, 400, 250, play_array);
                    graphics.renderTexture(temp_card.mycard, 400, 250, 6, 6);

                    SDL_RenderPresent(graphics.renderer);
                    if (temp_card.color != wild)
                    {
			            card_flag = 1;
                        played_card = temp_card;
		            }
                    /* if first card is wild, redraw */
		            else
			        temp_deck.add_card(temp_card);

	         }
	         bool force_draw_bool = false;
	        // int turn_flag = 1;
	         int win = 0 ;

	         while (win == 0 )
	          {

                graphics.renderTexture(played_card.mycard,400,250,6,6);
                SDL_RenderPresent(graphics.renderer);
		        player * curr_player = &play_array[0];
		        if (force_draw_bool)
		        {
		            if (played_card.number == 10)
		            {
		                card draw_2;
		                for (int i = 0 ; i < 2; i ++)
			            {
			                draw_2 = main_deck.draw();
                            curr_player->hand_add(draw_2);
			            }
                    }
		            if (played_card.number == 14)
		            {
		                card draw_4;
			            for (int i = 0 ; i < 4; i ++)
			            {
				         draw_4 = main_deck.draw();
				         curr_player->hand_add(draw_4);
			            }

		            }
			     force_draw_bool = false;
		       }
		       int check_flag = 0 ;
		      // cout<<played_card.color<<"ok"<<endl;
               //int index;
              // int size = curr_player->get_size();
               while (check_flag == 0)
               {

                   if( SDL_PollEvent(&e) != 0){
                   if(e.type==SDL_MOUSEBUTTONDOWN)
                   {
                       if(e.button.button==SDL_BUTTON_LEFT)
                       {
                           SDL_GetMouseState(&x,&y);
                           if(play_array[0].get_size() > mxwid/wcard)
                                      disbtw2card=mxwid/play_array[0].get_size();
                               else
                                      disbtw2card=wcard;
                              targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2-(play_array[0].get_size())*disbtw2card;
                           if(graphics.inside(x,y,graphics.toado(choosecolor,500,250,8,8)))
                           {
                               if(x>500&&x<547&&y>250&&y<250+47)played_card.color=blue;
                               if(x>547&&x<594&&y>250+47&&y<250+94)played_card.color=green;
                               if(x>547&&x<594&&y>250&&y<250+47)played_card.color=red;
                               if(x>500&&x<547&&y>250+47&&y<250+94)played_card.color=yellow;
                               cout<<played_card.color<<endl;
                               break;


                           }
                           if(graphics.inside(x,y,graphics.toado(backcard,300,220,6,6)))
                           {
                               card draw_temp;
                                main_deck.animateDeal(backcard,backcard, newbackground, graphics, 300, 250, targetX, targetY, play_array);
                               draw_temp = main_deck.draw();
                               curr_player->hand_add(draw_temp);
                               graphics.renderTexture(draw_temp.mycard, targetX, targetY, 6, 6);
                               SDL_RenderPresent(graphics.renderer);
                               if(play_array[0].get_size() > mxwid/wcard)
                                      disbtw2card=mxwid/play_array[0].get_size();
                               else
                                      disbtw2card=wcard;
                              targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2-(play_array[0].get_size())*disbtw2card;

                               break;
                            }

                             card tmp=curr_player->peek(x,y);
                             cout<<tmp.number<<' '<<tmp.color<<endl;
                             if(tmp.color==played_card.color||tmp.number==played_card.number||tmp.color==0)
                             {
                                    check_flag=1;
                                    curr_player->hand_remove(tmp);
                                    main_deck.animateDeal(backcard,tmp.mycard, newbackground, graphics, tmp.toadox, tmp.toadoy, 400, 250, play_array);
                                    temp_deck.add_card(tmp);
                                    played_card = tmp;
                                    if(played_card.color==wild)
                                    {
                                         graphics.renderTexture(choosecolor,500,250,8,8);
                                         SDL_RenderPresent(graphics.renderer);


                                    }


                             }

                        }

                    }
               }
               }

	           }



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
