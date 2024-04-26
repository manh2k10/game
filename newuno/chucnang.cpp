
#include"chucnang.h"

int targetX ;
int disbtw2card;
deck main_deck;
deck temp_deck;
player *play_array = new player[2];
ultis graphics;
SDL_Event e;
player * curr_play;
card played_card;
bool check=false;
bool quit;
bool   force_draw_bool;
bool checkboc=false;
ktlc myktlc;
void bocbai(int &x,int &y)
{
         if(play_array[0].get_size() > mxwid/wcard)
                disbtw2card=mxwid/play_array[0].get_size();
        else
                disbtw2card=wcard;
        targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2-(play_array[0].get_size())*disbtw2card;
        if(graphics.inside(x,y,graphics.toado(Resource::backcard,300,250,6,6)))
        {
            card draw_temp;
            myktlc.boc=true;
             Mix_PlayChannel(-1,Resource::drawcard,0);
            main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY, play_array);
            draw_temp = main_deck.draw();
            play_array[0].hand_add(draw_temp);
            graphics.renderTexture(draw_temp.mycard, targetX, targetY, 6, 6);
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
        checkboc=true;

}
void chonmau(int &x,int &y)
{
    //graphics.renderTexture(Resource::choosecolor,550,250,8,8);
   // SDL_RenderPresent(graphics.renderer);
    if(graphics.inside(x,y,graphics.toado(Resource::choosecolor,550,250,8,8)))
                           {
                               if(x>550&&x<597&&y>250&&y<250+47)
                               {
                                   played_card.color=blue;
                                   graphics.renderTexture(Resource::cblue,550,250,8,8);
                                    SDL_RenderPresent(graphics.renderer);
                               }
                               if(x>597&&x<634&&y>250+47&&y<250+94)
                               {
                                   played_card.color=green;
                                   graphics.renderTexture(Resource::cgreen,550,250,8,8);
                                    SDL_RenderPresent(graphics.renderer);
                               }

                               if(x>597&&x<634&&y>250&&y<250+47)
                               {
                                   played_card.color=red;
                                   graphics.renderTexture(Resource::cred,550,250,8,8);
                                    SDL_RenderPresent(graphics.renderer);
                               }
                               if(x>550&&x<597&&y>250+47&&y<250+94)
                               {
                                   played_card.color=yellow;
                                   graphics.renderTexture(Resource::cyellow,550,250,8,8);
                                    SDL_RenderPresent(graphics.renderer);
                               }
                               quit=true;
                               check=false;

                           }


            //SDL_RenderPresent(graphics.renderer);
}
void danhbai(int &x,int &y)
{

                    card tmp=play_array[0].peek(x,y);
                    if((tmp.color==played_card.color||tmp.number==played_card.number||tmp.color==0))
                    {
                        myktlc.danh=true;
                        play_array[0].hand_remove(tmp);
                         Mix_PlayChannel(-1,Resource::playgame,0);
                        main_deck.animateDeal(Resource::backcard,tmp.mycard,Resource:: newbackground, graphics, tmp.toadox, tmp.toadoy, 400, 250, play_array);
                        played_card = tmp;

                        temp_deck.add_card(tmp);

                        if(played_card.color==wild)
                        {
                            check=true;
                            graphics.renderTexture(Resource::choosecolor,550,250,8,8);
                            SDL_RenderPresent(graphics.renderer);

                        }
                        else quit=true;
                            if (played_card.number == 12 || played_card.number == 14)
					              {
						            force_draw_bool = true;
					              }

                    }

}
void nhanbai()
{

    if(play_array[1].get_size() > mxwid/wcard)
                                      disbtw2card=mxwid/play_array[1].get_size();
                               else
                                      disbtw2card=wcard;
                              targetX = (width+(play_array[1].get_size()-2)*disbtw2card)/2-(play_array[1].get_size())*disbtw2card;

		            if (played_card.number == 12)
		            {
		                card draw_2;
		                for (int i = 0 ; i < 2; i ++)
			            {
			                    Mix_PlayChannel(-1,Resource::drawcard,0);
			                   main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY-420, play_array);
                               draw_2 = main_deck.draw();
                               play_array[1].hand_add(draw_2);
                               graphics.renderTexture(Resource::backcard, targetX, targetY-420, 6, 6);
                               SDL_RenderPresent(graphics.renderer);
                               SDL_Rect src;
                               src.x=0;
                               src.y=0;
                               src.w=2560;
                               src.h=1440/3;
                               graphics.blitRect(Resource::newbackground,&src,0,0);
                               play_array[1].print(graphics,targetY-420,Resource::backcard,false);
                               if(play_array[1].get_size() > mxwid/wcard)
                                      disbtw2card=mxwid/play_array[1].get_size();
                               else
                                      disbtw2card=wcard;
                              targetX = (width+(play_array[1].get_size()-2)*disbtw2card)/2-(play_array[1].get_size())*disbtw2card;

			            }
                    }
		            if (played_card.number == 14)
		            {
		                card draw_4;
			            for (int i = 0 ; i < 4; i ++)
			            {
			                    Mix_PlayChannel(-1,Resource::drawcard,0);
				                main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY-420, play_array);
                               draw_4 = main_deck.draw();
                               play_array[1].hand_add(draw_4);
                               graphics.renderTexture(Resource::backcard, targetX, targetY-420, 6, 6);
                               SDL_RenderPresent(graphics.renderer);
                               SDL_Rect src;
                               src.x=0;
                               src.y=0;
                               src.w=2560;
                               src.h=1440/3;
                               graphics.blitRect(Resource::newbackground,&src,0,0);
                               play_array[1].print(graphics,targetY-420,Resource::backcard,false);
                               if(play_array[1].get_size() > mxwid/wcard)
                                      disbtw2card=mxwid/play_array[1].get_size();
                               else
                                      disbtw2card=wcard;
                              targetX = (width+(play_array[1].get_size()-2)*disbtw2card)/2-(play_array[1].get_size())*disbtw2card;

			            }
			            graphics.renderTexture(Resource::choosecolor,550,250,8,8);
    SDL_RenderPresent(graphics.renderer);

		            }
			     force_draw_bool = false;

}
