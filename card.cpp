#include "card.h"
card::card() : number(0), color(wild),mycard(nullptr),soluong(2)
{

}

card::card(int num, COLOR col,SDL_Texture* texture,int sl) : number(num), color(col),mycard(texture),soluong(sl)
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

/*void card::createcard(vector <card> &allcard,SDL_Renderer* renderer)
{
   // vector <card> allcard;

    for(int i=wild;i<=yellow;i++)
    {
        string s;

        if(i==wild)
        {
            tmp.number=13;
            tmp.color=wild;
            tmp.mycard=loadtexture("images/wild13.png",renderer);

            allcard.push_back(tmp);
            tmp.number=14;
            tmp.color=wild;
            tmp.mycard=loadtexture("images/wild14.png",renderer);

            allcard.push_back(tmp);

        }
        else for(int j=0;j<=12;j++)
        {

            switch(i)
            {
                 case red:
                     {
                          s="images/red.png";
                          if(j<10) s.insert(10,1,char(j+48));
                          else
                            switch(j)
                          {
                              case 10:s.insert(10,"10");break;
                              case 11:s.insert(10,"11");break;
                              case 12:s.insert(10,"12");break;
                          }
                          tmp.number=j;
                          tmp.color=red;
                          tmp.mycard=loadtexture(s,renderer);

                          allcard.push_back(tmp);

                          break;
                     }
                case blue:
                     {

                          s="images/blue.png";
                          if(j<10) s.insert(11,1,char(j+48));
                          else
                            switch(j)
                          {
                              case 10:s.insert(11,"10");break;
                              case 11:s.insert(11,"11");break;
                              case 12:s.insert(11,"12");break;
                          }
                          tmp.number=j;
                          tmp.color=blue;
                          tmp.mycard=loadtexture(s,renderer);
                          allcard.push_back(tmp);
                          break;
                     }
                case green:
                     {
                          s="images/green.png";
                          if(j<10) s.insert(12,1,char(j+48));
                          else
                            switch(j)
                          {
                              case 10:s.insert(12,"10");break;
                              case 11:s.insert(12,"11");break;
                              case 12:s.insert(12,"12");break;
                          }
                          tmp.number=j;
                          tmp.color=green;
                           tmp.mycard=loadtexture(s,renderer);

                          allcard.push_back(tmp);

                          break;
                     }
                case yellow:
                     {
                          s="images/yellow.png";
                          if(j<10) s.insert(13,1,char(j+48));
                          else
                            switch(j)
                          {
                              case 10:s.insert(13,"10");break;
                              case 11:s.insert(13,"11");break;
                              case 12:s.insert(13,"12");break;
                          }
                          tmp.number=j;
                          tmp.color=yellow;
                          tmp.mycard=loadtexture(s,renderer);

                          allcard.push_back(tmp);
                          break;
                     }


            }
            // if(tmp.mycard==nullptr)cout<<j<<' '<<tmp.color<<endl;

        }
    }
}

*/
