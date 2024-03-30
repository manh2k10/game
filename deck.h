#pragma once
#include "card.h"
#include "graphics.h"
#include<vector>
class deck : public card {
	public:
		deck();
		deck(const deck & other);
		const deck & operator= (const deck & other);
		~deck();
		void shuffle();
		void create();
		card draw();
		int add_card(card temp_card);
		void quick_shuffle();
		int get_size();

	private:
		vector<card> ptr_deck;
		int size;
		void clear();
		void copy(const deck & other);
};


