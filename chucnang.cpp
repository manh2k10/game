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
void bocbai(int &x,int &y)
{
         if(play_array[0].get_size() > mxwid/wcard)
                disbtw2card=mxwid/play_array[0].get_size();
        else
                disbtw2card=wcard;
        targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2-(play_array[0].get_size())*disbtw2card;
        if(graphics.inside(x,y,graphics.toado(Resource::backcard,300,220,6,6)))
        {
            card draw_temp;

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

}

void danhbai(int &x,int &y)
{

                    card tmp=play_array[0].peek(x,y);
                    if((tmp.color==played_card.color||tmp.number==played_card.number||tmp.color==0))
                    {

                        play_array[0].hand_remove(tmp);
                        main_deck.animateDeal(Resource::backcard,tmp.mycard,Resource:: newbackground, graphics, tmp.toadox, tmp.toadoy, 400, 250, play_array);
                        temp_deck.add_card(tmp);
                        played_card = tmp;
                        quit=true;
                        if(played_card.color==wild)
                        {
                            graphics.renderTexture(Resource::choosecolor,500,250,8,8);
                            SDL_RenderPresent(graphics.renderer);
                        }
                    }


}
