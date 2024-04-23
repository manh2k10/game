#include"game.h"
#include"resource.h"
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
    Resource::LoadAllData(graphics);
    SDL_RenderCopy(graphics.renderer,Resource::background,NULL,NULL);
    graphics.renderTexture(Resource::character,285,95,10,10);
    graphics.renderTexture(Resource::play,390,430,6,6);
    SDL_RenderPresent(graphics.renderer);
    deck main_deck;
    main_deck.create(graphics);
    main_deck.quick_shuffle();
    player * play_array;
	play_array = new player[2];

    int disbtw2card;
    if(play_array[0].get_size() > mxwid/wcard)
           disbtw2card=mxwid/play_array[0].get_size();
    else
          disbtw2card=wcard;

    int targetX = (width+(play_array[0].get_size()-2)*disbtw2card)/2;// Tọa độ X mục tiêu của quân bài


    int targetY = 460; // Tọa độ Y mục tiêu của quân bài
    bool cardDealt = false;
    SDL_Event e;
    bool kt=false;
    while (m_isRunning)
    {
      // Uint32 windowID = SDL_GetWindowID(graphics.window);
        if( SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)m_isRunning=false;
            int x,y;
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                if(e.button.button==SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&x,&y);
                    cout<<x<<' '<<y<<endl;
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
              //  SDL_RenderPresent(graphics.renderer);
                cardDealt=true;
                deck temp_deck;
            card played_card;
            card temp_card;
	        int card_flag = 0 ;
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
	         bool force_draw_bool = false;
	        // int turn_flag = 1;
	         int win = 0 ;
             kt=false;
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
			                   main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY, play_array);
                               draw_2 = main_deck.draw();
                               curr_player->hand_add(draw_2);
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
				         main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY, play_array);
                               draw_4 = main_deck.draw();
                               curr_player->hand_add(draw_4);
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

		            }
			     force_draw_bool = false;
		       }
		       int check_flag = 0 ;

               while (check_flag == 0)
               {

                   while( SDL_PollEvent(&e) != 0){
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

                           if(check_flag!=1&&graphics.inside(x,y,graphics.toado(Resource::backcard,300,220,6,6)))
                           {
                                card draw_temp;
                                main_deck.animateDeal(Resource::backcard,Resource::backcard,Resource:: newbackground, graphics, 300, 250, targetX, targetY, play_array);
                               draw_temp = main_deck.draw();
                               curr_player->hand_add(draw_temp);
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

                               check_flag=1;
                            }

                             card tmp=curr_player->peek(x,y);
                             if(check_flag!=1&&tmp.color==played_card.color||tmp.number==played_card.number||tmp.color==0)
                             {
                                    check_flag=1;
                                    curr_player->hand_remove(tmp);
                                    main_deck.animateDeal(Resource::backcard,tmp.mycard,Resource:: newbackground, graphics, tmp.toadox, tmp.toadoy, 400, 250, play_array);
                                    temp_deck.add_card(tmp);
                                    played_card = tmp;

                                    if(played_card.color==wild)
                                    {
                                         graphics.renderTexture(Resource::choosecolor,500,250,8,8);
                                         SDL_RenderPresent(graphics.renderer);
                                         kt=true;

                                    }
                                    if (played_card.number >= 10 && played_card.number <= 14)
					                {
						               force_draw_bool = true;
					                }
					                //check_flag=1;
                             }

		                     }
                   }
                        if(e.type==SDL_MOUSEBUTTONDOWN)
                               {
                                  if(e.button.button==SDL_BUTTON_LEFT)
                                  {
                                  SDL_GetMouseState(&x,&y);
                                  if(kt&&graphics.inside(x,y,graphics.toado(Resource::choosecolor,500,250,8,8)))
                                 {
                                      if(x>500&&x<547&&y>250&&y<250+47)played_card.color=blue;
                                      if(x>547&&x<594&&y>250+47&&y<250+94)played_card.color=green;
                                      if(x>547&&x<594&&y>250&&y<250+47)played_card.color=red;
                                      if(x>500&&x<547&&y>250+47&&y<250+94)played_card.color=yellow;
                                      kt=false;
                                      check_flag=1;
                                 }
                                  }
                               }




                             if ( curr_player->get_size() == 0 )
		                     {
			                     win =1;
			                     cout  << " has won the game." << endl;
			                     break;
		                     }

                    }
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

}

void Game::Terminate()
{//dung chuong trinh
    graphics.close();
}

