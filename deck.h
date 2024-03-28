#pragma once
#include "card.h"
class deck : public card {
	public:
		deck();
		deck(const deck & other);
		const deck & operator= (const deck & other);
		~deck();
		void shuffle();
		card draw();
		void create();
		int add_card(card temp_card);
		void quick_shuffle();
		void print_deck();
		int get_size();

	private:
		card * ptr_deck;
		int size;
		void clear();
		void copy(const deck & other);
};

