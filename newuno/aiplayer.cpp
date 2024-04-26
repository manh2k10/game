
#include"aiplayer.h"
#include <cstdlib>
#include<time.h>
//#include<bits/stdc++.h>

 int kcach;
    int target;
    bool ncheckboc=false;
    bool ncheck=false;

int choosecolor()
{
    srand(time(0));
    int res=rand()%4+1;
    return res;
}
void playcard()
{

    card tmp=play_array[1].choosecard(played_card);
    play_array[1].hand_remove(tmp);
     Mix_PlayChannel(-1,Resource::playgame,0);
    main_deck.animateDeal(Resource::backcard,tmp.mycard,Resource:: newbackground, graphics, tmp.toadox, tmp.toadoy, 400, 250, play_array);
    temp_deck.add_card(tmp);

    played_card = tmp;
    if(played_card.color==wild)
        {
                check=true;
                int color=choosecolor();
                switch(color)
                {
                    case 1:
                        {
                            played_card.color=yellow;

                            break;
                        }
                    case 2:
                        {
                          played_card.color=red;

                         break;
                        }
                    case 3:
                        {
                             played_card.color=blue;
                            break;
                        }
                    case 4:
                        {
                            played_card.color=green;

                                break;
                        }
                }


         }
    else quit=true;
    if (played_card.number >=12 || played_card.number <= 14)
    {
          ncheck = true;
    }

}
void ainhanbai()
{

		          if ( ncheck)
		        {
		            if(play_array[0].get_size() > mxwid/wcard)
                                      disbtw2card=mxwid/play_array[0].get_size();
                               else
                                      disbtw2card=wcard;
                              targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2-(play_array[0].get_size())*disbtw2card;
		            if (played_card.number == 12)
		            {
		                card draw_2;
		                for (int i = 0 ; i < 2; i ++)
			            {
                               Mix_PlayChannel(-1,Resource::drawcard,0);
			                   main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY, play_array);
                               draw_2 = main_deck.draw();
                               play_array[0].hand_add(draw_2);
                               graphics.renderTexture(draw_2.mycard, targetX, targetY, 6, 6);
                               SDL_RenderPresent(graphics.renderer);
                               SDL_Rect src;
                               src.x=0;
                               src.y=1440/3*2;
                               src.w=2560;
                               src.h=1440/3;
                               graphics.blitRect(Resource::newbackground,&src,0,400);
                               play_array[0].print(graphics,targetY,Resource::backcard,true);
                               if(play_array[0].get_size() > mxwid/wcard)
                                      disbtw2card=mxwid/play_array[0].get_size();
                               else
                                      disbtw2card=wcard;
                              targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2-(play_array[0].get_size())*disbtw2card;

			            }
                    }
		            if (played_card.number == 14)
		            {
		                card draw_4;
			            for (int i = 0 ; i < 4; i ++)
			            {
			                     Mix_PlayChannel(-1,Resource::drawcard,0);
				                main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY, play_array);
                               draw_4 = main_deck.draw();
                               play_array[0].hand_add(draw_4);
                               graphics.renderTexture(draw_4.mycard, targetX, targetY, 6, 6);
                               SDL_RenderPresent(graphics.renderer);
                               SDL_Rect src;
                               src.x=0;
                               src.y=1440/3*2;
                               src.w=2560;
                               src.h=1440/3;
                               graphics.blitRect(Resource::newbackground,&src,0,400);
                               play_array[0].print(graphics,targetY,Resource::backcard,true);
                               if(play_array[0].get_size() > mxwid/wcard)
                                      disbtw2card=mxwid/play_array[0].get_size();
                               else
                                      disbtw2card=wcard;
                              targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2-(play_array[0].get_size())*disbtw2card;


		            }
			    ncheck = false;
		       }
        }

}
void aibocbai()
{
         if(play_array[1].get_size() > mxwid/wcard)
                disbtw2card=mxwid/play_array[1].get_size();
        else
                disbtw2card=wcard;
        targetX = (width+(play_array[1].get_size()-2)*disbtw2card)/2-(play_array[1].get_size())*disbtw2card;

        card draw_temp;
         Mix_PlayChannel(-1,Resource::drawcard,0);
        main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY-420, play_array);
        draw_temp = main_deck.draw();
        play_array[1].hand_add(draw_temp);
        graphics.renderTexture(Resource::backcard, targetX, targetY-420, 6, 6);
        SDL_RenderPresent(graphics.renderer);
        SDL_Rect src;
        src.x=0;
        src.y=0;
        src.w=2560;
        src.h=1440/3;
        graphics.blitRect(Resource::newbackground,&src,0,0);
        play_array[1].print(graphics,targetY-420,Resource::backcard,false);
        ncheckboc=true;
}

void playturn()
{
    ncheckboc=false;

    bool luotchoi=true;
    bool checkluotchoi=false;
     while(luotchoi)
    {
           if(play_array[1].get_size()==0)
                  {
                      break;
                  }
            if(!ncheckboc&&!play_array[1].mycheck(played_card))aibocbai();
            if(!play_array[1].mycheck(played_card)){luotchoi=false;}//ktra neu sau khi boc ma vx ko co bai nao choi dc het luot choi
            if(play_array[1].mycheck(played_card)){checkluotchoi=false;}
            if(play_array[1].mycheck(played_card))
                {
                    playcard();
                    if(ncheck)
                    {
                        ainhanbai();
                        switch(played_card.color)
                {
                    case 1:
                        {
                            played_card.color=yellow;
                            graphics.renderTexture(Resource::cyellow,550,250,8,8);
                            break;
                        }
                    case 0:{break;}
                    case 2:
                        {
                          played_card.color=red;
                         graphics.renderTexture(Resource::cred,550,250,8,8);
                         break;
                        }
                    case 3:
                        {
                             played_card.color=blue;
                            graphics.renderTexture(Resource::cblue,550,250,8,8);
                            break;
                        }
                    case 4:
                        {
                            played_card.color=green;
                                   graphics.renderTexture(Resource::cgreen,550,250,8,8);
                                break;
                        }
                }}
                    luotchoi=false;

                    if(checkluotchoi==false&&(played_card.number==10||played_card.number==11))
                        {
                            luotchoi=true;
                            checkluotchoi=true;
                            ncheckboc=false;
                        }
            }


    }
}




