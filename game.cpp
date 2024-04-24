#include"game.h"
#include"resource.h"
#include"aiplayer.h"
static Game* g_game=nullptr;
Game::Game()
{
    Initialize();

}
Game::~Game()
{
    //huy game
    Terminate();
}
void Game::Run()
{

    main_deck.create(graphics);
    main_deck.quick_shuffle();
    if(play_array[0].get_size() > mxwid/wcard)
           disbtw2card=mxwid/play_array[0].get_size();
    else
          disbtw2card=wcard;

     targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2;// Tọa độ X mục tiêu của quân bài


    // Tọa độ Y mục tiêu của quân bài
    bool cardDealt = false;
    bool kt=false;
     m_isRunning=true;
    while (m_isRunning)
    {
      // Uint32 windowID = SDL_GetWindowID(graphics.window);
        while( SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)m_isRunning=false;
            int x,y;
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                if(e.button.button==SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&x,&y);
                    if(graphics.inside(x,y,graphics.toado(Resource::play,390,430,6,6)))
                    {
                        kt=true;

                    }
                }
            }
            if (kt && !cardDealt)
            {
                SDL_RenderClear(graphics.renderer);
                SDL_RenderCopy(graphics.renderer,Resource::newbackground,NULL,NULL);
                graphics.renderTexture(Resource::backcard,300,220,6,6);
                SDL_RenderPresent(graphics.renderer);
                // phát bài
                for(int i=0;i<7;i++)
                {

                    main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY, play_array);
                    card temp_card;
			        temp_card = main_deck.draw();
			        temp_card.toadox=targetX;
			        temp_card.toadoy=targetY;
			        play_array[0].hand_add(temp_card);
                    graphics.renderTexture(temp_card.mycard, targetX, targetY, 6, 6);
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
            deck temp_deck;
            card temp_card;
	        int card_flag = 0 ;
	        // xac dinh la bai dau tien
	        while (card_flag == 0 )
            {
                    temp_card = main_deck.draw();
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
			        temp_deck.add_card(temp_card);

	         }
	         force_draw_bool = false;
	        // int turn_flag = 1;
	         int win = 0;
             kt=false;
	         while (win == 0 )
	          {
              //  cout<<"true"<<endl;
                graphics.renderTexture(played_card.mycard,400,250,6,6);
                SDL_RenderPresent(graphics.renderer);
			     force_draw_bool = false;
		         quit=false;
		         checkboc=false;
                 //check=false;
                 bool luotchoi=true;
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

                         if(e.type == SDL_QUIT){m_isRunning=false;}
                         if(e.type==SDL_MOUSEBUTTONDOWN)
                         {
                             if(e.button.button==SDL_BUTTON_LEFT)
                             {
                                  SDL_GetMouseState(&x,&y);
                                   if(!checkboc)bocbai(x,y);
                                  if(!play_array[0].mycheck(played_card)){luotchoi=false;quit=true;}
                                  if(y>460&&y<460+126){danhbai(x,y);if(check==false)luotchoi=false;}
                                  cout<<check<<endl;
                                  if(check)
                                  {chonmau(x,y);luotchoi=false;}
                                  if(force_draw_bool)nhanbai();


                             }
                        }

                     }
                    // check=false;


                  }
                  if(played_card.number==10||played_card.number==11)
                                        luotchoi=true;
                 }


                  if(play_array[0].get_size()==0)
                  {
                      win=1;
                      cout<<"you win";
                  }
                   playturn();
                  if(play_array[1].get_size()==0)
                  {
                      win=1;
                      cout<<"you lose";
                  }

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
    graphics.renderTexture(Resource::play,390,430,6,6);
    SDL_RenderPresent(graphics.renderer);

}

void Game::Terminate()
{//dung chuong trinh
    graphics.close();
}

