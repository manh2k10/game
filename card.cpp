#include "card.h"
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "sdl_ultis.h"
#include<string>
card::card() : number(0), color(wild),mycard(NULL),myrender(NULL)
{

}

card::card(int num, COLOR col,SDL_Texture* texture,SDL_Renderer*renderer) : number(num), color(col), mycard(texture),myrender(renderer)
{

}

bool card::operator==(card const & other) const
{
	return number == other.number || color == other.color || color == wild || other.color == wild;

}


bool card::operator!=(card const & other) const
{
	return !(*this == other) ;
}

void createcard()
{
    card tmp;
    for(int i=wild;i<=yellow;i++)
    {
        string s;

        if(i==wild)
        {
            tmp.number=13;
            tmp.color=wild;
            tmp.mycard=loadtexture("images/wild13.png",tmp.myrender);
            SDL_RenderCopy(tmp.myrender,tmp.mycard,NULL,NULL);
            allcard.push_back(tmp);
            tmp.number=14;
            tmp.color=wild;
            tmp.mycard=loadtexture("images/wild14.png",tmp.myrender);
            SDL_RenderCopy(tmp.myrender,tmp.mycard,NULL,NULL);
            allcard.push_back(tmp);

        }
        else for(int j=0;j<=12;j++)
        {
            switch(i)
            {
                 case red:
                     {
                          s="images/red.png";
                          s.insert(10,1,char(j+48));
                          tmp.number=j;
                          tmp.color=red;
                          tmp.mycard=loadtexture(s,tmp.myrender);
                          SDL_RenderCopy(tmp.myrender,tmp.mycard,NULL,NULL);
                          allcard.push_back(tmp);
                          break;
                     }
                case blue:
                     {
                          s="images/blue.png";
                          s.insert(11,1,char(j+48));
                          tmp.number=j;
                          tmp.color=blue;
                          tmp.mycard=loadtexture(s,tmp.myrender);
                          SDL_RenderCopy(tmp.myrender,tmp.mycard,NULL,NULL);
                          allcard.push_back(tmp);
                          break;
                     }
                case green:
                     {
                          s="images/green.png";
                          s.insert(12,1,char(j+48));
                          tmp.number=j;
                          tmp.color=green;
                          tmp.mycard=loadtexture(s,tmp.myrender);
                          SDL_RenderCopy(tmp.myrender,tmp.mycard,NULL,NULL);
                          allcard.push_back(tmp);
                          break;
                     }
                case yellow:
                     {
                          s="images/yellow.png";
                          s.insert(13,1,char(j+48));
                          tmp.number=j;
                          tmp.color=yellow;
                          tmp.mycard=loadtexture(s,tmp.myrender);
                          SDL_RenderCopy(tmp.myrender,tmp.mycard,NULL,NULL);
                          break;
                     }



            }


        }
    }
}

