#include "card.h"
#include "player.h"

#include <cmath>

player::player()
{
	head = NULL;
	size = 0;
}
player::player(const player & other)
{
	copy(other);
}

const player & player::operator= (const player & other)
{
	if ( this != &other)
	{
		clear();
		copy(other);
	}

	return *this;

}
player::~player()
{
	clear();
}
void player::hand_add(card temp_card)
{

	card_elem * temp_ptr;
	temp_ptr = new card_elem();
	temp_ptr->data = temp_card;
//	temp_ptr->data.toadox = head->data.toadox+50;;
	temp_ptr->next = head;

	head = temp_ptr;
	size++;

}

card player::hand_remove(card tmp)
{
    card_elem* prev_ptr = head;
    card_elem* target = prev_ptr->next;
    card temp_card;

    if (head != nullptr && head->data.toadox == tmp.toadox && head->data.toadoy == tmp.toadoy)
    {
        temp_card = head->data;
        head = head->next;
        size--;
        return temp_card;
    }


    while (target != nullptr)
    {
        if (target->data.toadox == tmp.toadox && target->data.toadoy == tmp.toadoy)
        {
            card_elem* temp = head;

             while (temp != target )
            {
              temp->data.toadox += 50;
              temp = temp->next;
            }
            prev_ptr->next = target->next;
            temp_card = target->data;
            delete target;
             size--;
            return temp_card;
        }
        prev_ptr = target;
        target = target->next;
    }

    // Trường hợp không tìm thấy lá bài có tọa độ (x, y)
    // Có thể xử lý bằng cách trả về giá trị mặc định hoặc thông báo lỗi
    return card();
}



void player::uno()
{

}


void player::copy(const player & other)
{
	size = other.size;


	if (size > 0 )
	{
		head = new card_elem();

		head->data = other.head->data;
	}
	else
	{
		head = NULL;
		return;
	}


	card_elem * other_ptr = other.head->next;

	card_elem * temp_ptr;card_elem * prev_ptr = head;
	for (int i=1 ; i<size; i++)
	{

		temp_ptr = new card_elem();

		prev_ptr->next = temp_ptr;

		temp_ptr->data = other_ptr->data;

		prev_ptr = temp_ptr;
		temp_ptr = NULL;
		other_ptr = other_ptr->next;
	}

}

void player::clear()
{
	card_elem * temp_ptr = head;
	card_elem * next_ptr;
	while (size > 0)
	{
		next_ptr = temp_ptr->next;
		delete temp_ptr;
		temp_ptr = next_ptr;
		size--;
	}
	head = NULL;
}

int player::get_size() const
{
	return size;
}

card player::peek(int x,int y) const
{

	card_elem * temp_elem = head;
	int disbtw2card;
    if(size> (int)mxwid/wcard)
           disbtw2card=mxwid/size;
    else
          disbtw2card=wcard;
   // int tempx = (width+(size-2)*disbtw2card)/2;
	while ( temp_elem!=nullptr)
	{
	     if ((x>=temp_elem->data.toadox+(wcard-disbtw2card))&&(x<temp_elem->data.toadox+81)&&(y>=temp_elem->data.toadoy)&&(y<temp_elem->data.toadoy+126))
            	return temp_elem->data;
		  temp_elem = temp_elem->next;

	}

	return temp_elem->data;

}
void player::print(ultis graphics, int y_pos,SDL_Texture* texture,bool kt) const
{
    std::vector<card_elem*> elements; // Lưu trữ các phần tử theo thứ tự ngược
    card_elem* temp_ptr = head;
    while (temp_ptr != nullptr)
    {
        elements.push_back(temp_ptr);
        temp_ptr = temp_ptr->next;
    }
      int disbtw2card;
    if(size> (int)mxwid/wcard)
           disbtw2card=mxwid/size;
    else
          disbtw2card=wcard;
    int tempx = (width+(size-2)*disbtw2card)/2;
    for (int i = elements.size() - 1; i >= 0; i--)
    {
        if(kt)graphics.renderTexture(elements[i]->data.mycard, tempx, y_pos, 6, 6);
        else graphics.renderTexture(texture, tempx, y_pos, 6, 6);
        elements[i]->data.toadox=tempx;
        elements[i]->data.toadoy=y_pos;
        tempx -= disbtw2card;


    }
    SDL_RenderPresent(graphics.renderer);
}
bool player::mycheck(card playedcard)
{
    card_elem* temp_ptr = head;
    while (temp_ptr != nullptr)
    {
        if(temp_ptr->data.number==playedcard.number||temp_ptr->data.color==playedcard.color||temp_ptr->data.color==wild)return true;
        temp_ptr = temp_ptr->next;
    }
    return false;
}
card  player::choosecard(card played_card)
{
    card chosencard=card();
     for (card_elem* current = head; current != NULL; current = current->next) {
            if (current->data.color == played_card.color || current->data.number == played_card.number||current->data.color==wild) {
                chosencard = current->data;
                break;
            }
        }
        return chosencard;

}
