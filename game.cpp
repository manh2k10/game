#include"game.h"
#include"resource.h"
#include"aiplayer.h"
static Game* g_game=nullptr;
bool kt=false;
Game::Game()
{
    Initialize();

}
Game::~Game()
{
    //huy game
    Terminate();
}
void Game::choilai(bool &kt,bool &cardDealt,bool & m_isRunning)
{
    while( SDL_PollEvent(&e) != 0)
        {
            cout<<226;
            if(e.type == SDL_QUIT){m_isRunning=false;break;}
            int x,y;
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                if(e.button.button==SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&x,&y);cout<<226;

                    if(graphics.inside(x,y,graphics.toado(Resource::playagain,350,450,2,2)))
                    {
                        kt=true;
                        cardDealt=false;
                        Reset();
                        main_deck.create(graphics);
                        SDL_RenderClear(graphics.renderer);

                        break;


                    }
                    if(graphics.inside(x,y,graphics.toado(Resource::exit,350,500,2,2)))
                    {

                       m_isRunning=false;

                       break;
                    }
                }
            }
        }
}
void Game::Run()
{
    Mix_PlayMusic( Resource::nhacnen, -1 );
    main_deck.create(graphics);

    // Tọa độ Y mục tiêu của quân bài
    bool cardDealt = false;

    m_isRunning=true;
    bool running=true;
   while(running)
     {while( SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT){m_isRunning=false;running=false;}
            int x,y;
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                if(e.button.button==SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&x,&y);

                    if(graphics.inside(x,y,graphics.toado(Resource::play,350,410,2,2)))
                    {
                        kt=true;
                        running=false;
                        break;


                    }
                    if(graphics.inside(x,y,graphics.toado(Resource::exit,350,500,2,2)))
                    {
                       cout<<x<<y;
                       m_isRunning=false;
                       running=false;
                       break;
                    }
                }
            }
        }
        if(running==false)break;
     }
    main_deck.create(graphics);
    while (m_isRunning)
    {

            choilai(kt,cardDealt,m_isRunning);
             if(m_isRunning==false)break;
            main_deck.quick_shuffle();
            while( SDL_PollEvent(&e) != 0)
            if(e.type == SDL_QUIT){m_isRunning=false;running=false;}

            if (kt && !cardDealt)
            {
                cardDealt=true;

                if(play_array[0].get_size() > mxwid/wcard)
                     disbtw2card=mxwid/play_array[0].get_size();
                else
                     disbtw2card=wcard;

                targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2;// Tọa độ X mục tiêu của quân bài
                 Mix_PlayMusic( Resource::nhacnen, -1 );
                SDL_RenderClear(graphics.renderer);
                SDL_RenderCopy(graphics.renderer,Resource::newbackground,NULL,NULL);
                graphics.renderTexture(Resource::backcard,300,220,6,6);
                SDL_RenderPresent(graphics.renderer);
                // phát bài
                for(int i=0;i<7;i++)
                {
                    Mix_PlayChannel(-1,Resource::drawcard,0);
                    main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY, play_array);
                    card temp_card;
			        temp_card = main_deck.draw();
			        temp_card.toadox=targetX;
			        temp_card.toadoy=targetY;
			        play_array[0].hand_add(temp_card);
                    graphics.renderTexture(temp_card.mycard, targetX, targetY, 6, 6);
                    Mix_PlayChannel(-1,Resource::drawcard,0);
                    main_deck.animateDeal(Resource::backcard,Resource::backcard, Resource::newbackground, graphics, 300, 250, targetX, targetY-420, play_array);
                    temp_card = main_deck.draw();
			        play_array[1].hand_add(temp_card);
                    graphics.renderTexture(Resource::backcard, targetX, targetY-420, 6, 6);
                     if(play_array[0].get_size() > mxwid/wcard)
                        disbtw2card=mxwid/play_array[0].get_size();
                     else
                         disbtw2card=wcard;
                    targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2-(play_array[0].get_size())*disbtw2card;
                    SDL_Delay(10);
                      SDL_RenderPresent(graphics.renderer);
                }


            card temp_card;
	        int card_flag = 0 ;
	        // xac dinh la bai dau tien
	        SDL_Delay(100);
	        while (card_flag == 0 )
            {
                    temp_card = main_deck.draw();
                    Mix_PlayChannel(-1,Resource::drawcard,0);
                    main_deck.animateDeal(Resource::backcard,Resource::backcard, Resource::newbackground, graphics, 300, 250, 400, 250, play_array);
                    graphics.renderTexture(temp_card.mycard, 400, 250, 6, 6);

                    SDL_RenderPresent(graphics.renderer);
                    if (temp_card.color != wild)
                    {
			            card_flag = 1;
                        played_card = temp_card;
		            }
                    /* if first card is wild, redraw */
		            else
			        {  temp_deck.add_card(temp_card);cout<<temp_deck.add_card(temp_card);}



	         }
	         force_draw_bool = false;
	        // int turn_flag = 1;
	         int win = 0;
             kt=false;
	         while (win == 0 )
	          {

                graphics.renderTexture(played_card.mycard,400,250,6,6);
                SDL_RenderPresent(graphics.renderer);
			     force_draw_bool = false;
		         quit=false;
		         checkboc=false;
                 //check=false;
                 if(play_array[0].get_size()==0)
                  {
                      win=1;
                      cout<<"you win";
                      SDL_RenderClear(graphics.renderer);
                       SDL_RenderCopy(graphics.renderer,Resource::newbackground,NULL,NULL);
                      graphics.renderTexture(Resource::youwin,100,200,1,1);
                      graphics.renderTexture(Resource::playagain,350,410,2,2);
                        graphics.renderTexture(Resource::exit,350,500,2,2);
                      SDL_RenderPresent(graphics.renderer);

                      break;
                  }
                 bool luotchoi=true;
                 bool checkluotchoi=false;

                 myktlc.boc=false;
                 myktlc.danh=false;
                 while(luotchoi)
                 {

                     checkboc=false;
                     quit=false;
		         while(!quit)
                 {
                     graphics.renderTexture(played_card.mycard,400,250,6,6);
                     SDL_RenderPresent(graphics.renderer);
                     while( SDL_PollEvent(&e) != 0)
                     {

                         if(e.type == SDL_QUIT){ m_isRunning=false; quit=true;win=1;break;}
                         if(e.type==SDL_MOUSEBUTTONDOWN)
                         {
                             if(e.button.button==SDL_BUTTON_LEFT)
                             {
                                 int x,y;
                                  SDL_GetMouseState(&x,&y);
                                   if(!checkboc)bocbai(x,y);
                                   if(play_array[0].mycheck(played_card)){checkluotchoi=false;}
                                  if(!play_array[0].mycheck(played_card)){luotchoi=false;quit=true;}
                                  if(y>460&&y<460+126){danhbai(x,y);if(check==false)luotchoi=false;}
                                  ;
                                  if(check)
                                  {chonmau(x,y);luotchoi=false;}
                                  if(force_draw_bool)nhanbai();




                             }
                        }

                     }
                    // check=false;
                  }

                   if(play_array[0].get_size()==0)
                  {
                      win=1;
                       Mix_HaltMusic();
                      SDL_RenderClear(graphics.renderer);
                       Mix_PlayChannel(-1,Resource::winner,0);
                      SDL_RenderCopy(graphics.renderer,Resource::newbackground,NULL,NULL);
                      graphics.renderTexture(Resource::youwin,230,100,1,1);
                      graphics.renderTexture(Resource::playagain,350,410,2,2);
                        graphics.renderTexture(Resource::exit,350,500,2,2);
                      SDL_RenderPresent(graphics.renderer);

                      break;
                  }

                  if(checkluotchoi==false&&(played_card.number==10||played_card.number==11))
                   {
                       luotchoi=true;
                       checkluotchoi=true;
                   }

                   if(myktlc.boc==false&&myktlc.danh==false)luotchoi=true;
                 }

                  if(play_array[0].get_size()==0)
                  {
                      win=1;
                       Mix_HaltMusic();
                      SDL_RenderClear(graphics.renderer);
                       Mix_PlayChannel(-1,Resource::winner,0);
                      SDL_RenderCopy(graphics.renderer,Resource::newbackground,NULL,NULL);
                      graphics.renderTexture(Resource::youwin,230,100,1,1);
                      graphics.renderTexture(Resource::playagain,350,410,2,2);
                        graphics.renderTexture(Resource::exit,350,500,2,2);

                      SDL_RenderPresent(graphics.renderer);

                      break;
                  }

                   playturn();

                  if(play_array[1].get_size()==0)
                  {
                      win=1;
                       Mix_HaltMusic();
                       Mix_PlayChannel(-1,Resource::loser,0);
                      SDL_RenderClear(graphics.renderer);
                      SDL_RenderCopy(graphics.renderer,Resource::newbackground,NULL,NULL);
                      graphics.renderTexture(Resource::youlose,150,0,2,2);
                       graphics.renderTexture(Resource::playagain,350,410,2,2);
                        graphics.renderTexture(Resource::exit,350,500,2,2);

                      SDL_RenderPresent(graphics.renderer);
                      break;

                  }

                  if (main_deck.get_size() < 10)
		           {
			         // flush remaining cards from main to temp deck
			         for (int i =0 ; i < main_deck.get_size();)
			         {
				      temp_deck.add_card(main_deck.draw());
				      cout<<main_deck.get_size();
			          }
                    //recreate main_deck and shuffle it
			           main_deck = temp_deck;

			           main_deck.quick_shuffle();

			          temp_deck = deck();

		           }

                }
	          }

    }
}

Game* Game::GetInstance()
{
    if(g_game==nullptr)//kiem tra xem co doi tuong game nao duoc tao chua
    {
        g_game=new Game();
    }
    return g_game;
}



void Game::Initialize()
{//KHOI TAO SDL2
    graphics.SDLInit();
    m_isRunning=true;
    Resource::LoadAllData(graphics);
    SDL_RenderCopy(graphics.renderer,Resource::background,NULL,NULL);
    graphics.renderTexture(Resource::character,285,95,10,10);
    graphics.renderTexture(Resource::play,350,410,2,2);
    graphics.renderTexture(Resource::exit,350,500,2,2);

    SDL_RenderPresent(graphics.renderer);

}

void Game::Terminate()
{//dung chuong trinh
    for(int i=0;i<108;i++)free(main_deck.mycard);
     free(Resource::backcard);
     free(Resource::background);
     free(Resource::newbackground);

     free(Resource::character);
     free(Resource::choosecolor);
     free(Resource::play);

     free(Resource::cblue);
     free(Resource::cgreen);
     free(Resource::cred);
     free(Resource::cyellow);

     free(Resource::youlose);
     free(Resource::youwin);
     free(Resource::exit);
     free(Resource::playagain);


    graphics.close();
}
void Game::Reset()
{
    deck newdeck;

    temp_deck=newdeck;
    newdeck.create(graphics);
    newdeck.quick_shuffle();
    main_deck=newdeck;

    played_card=card();
    play_array[0]=player();
    play_array[1]=player();
}
