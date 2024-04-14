#pragma once
#include"player.h"
#include"card.h"
class aiplayer: public player
{
  public:
      card choosecard();
      void playcard();
};
