#pragma once
#include "card.h"
#include <cstdlib>
#include <ctime>
#include"player.h"
#include "graphics.h"
class deck : public card {
public:
    deck();
    deck(const deck &other);
    const deck &operator= (const deck &other);
    ~deck();
    void shuffle();
    void create(ultis graphics);
    card draw();
    int add_card(card temp_card);
    void quick_shuffle();
    int get_size();
    void animateDeal(SDL_Texture* texture,SDL_Texture* background,ultis graphics,int startX, int startY, int endX, int endY,player temp_player[]);
     card* ptr_deck;

      private:
    int size;

    void clear();
    void copy(const deck &other);
};
