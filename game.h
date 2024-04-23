#pragma once
#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"graphics.h"
#include"card.h"
#include"deck.h"
#include"player.h"
#include"def.h"
class Game
{

private:
    ultis graphics;
    bool m_isRunning;
public:
    Game();
    ~Game();
    void Run();
    static Game* GetInstance();
private:
//ham khoi tao game
    void Initialize();
    //ham  huy game
    void Terminate();
};
