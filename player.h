#pragma once
#include "card.h"
#include "graphics.h"
#include"SDL.h"
#include"SDL_image.h"
class player
{
	public:
		player();
		player(const player & other);
		const player & operator= (const player & other);
		~player();
		void hand_add(card temp);
		card hand_remove(card tmp);
		void uno();
        void print(ultis graphics,int y_pos,SDL_Texture* texture,bool kt) const;
		int get_size() const;
		card peek(int x,int y) const;
	private:
		class card_elem
		{
		  public:
			card_elem()
			{
				next = NULL;
			}
			card data;
			card_elem * next;
		};


		card_elem * head;
		int size;
		void copy(const player & other);
		void clear();
};
