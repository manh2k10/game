#pragma once
#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"graphics.h"
#include"card.h"
#include"deck.h"
#include"player.h"
#include"def.h"
#include"chucnang.h"
class Game
{

private:
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
    //reset
    void Reset();
};
