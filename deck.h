#pragma once
#include "card.h"
#include <cstdlib>
#include <ctime>
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

     card* ptr_deck;
      private:
    int size;

    void clear();
    void copy(const deck &other);
};
