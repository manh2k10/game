#include"game.h"
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

