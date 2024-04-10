#pragma once
#include "card.h"
class player
{
	public:
		player();
		player(const player & other);
		const player & operator= (const player & other);
		~player();
		void hand_add(card temp);
		card hand_remove(int pos);
		void uno();

		int get_size() const;
		card peek(int pos) const;
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


/*void animateDeal(int startX, int startY, int endX, int endY)
{
    int frames = 30; // Số khung hình trong quá trình di chuyển
    int currentFrame = 0;

    int deltaX = (endX - startX) / frames;
    int deltaY = (endY - startY) / frames;

    int currentX = startX;
    int currentY = startY;

    while (currentFrame < frames) {
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        renderCard(currentX, currentY);

        SDL_RenderPresent(gRenderer);

        currentX += deltaX;
        currentY += deltaY;

        currentFrame++;

        SDL_Delay(10); // Đợi một thời gian ngắn giữa các khung hình
    }*/
