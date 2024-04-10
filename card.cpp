#include "card.h"
card::card() : number(0), color(wild),mycard(nullptr)
{

}


card::card(int num, COLOR col,SDL_Texture* texture) : number(num), color(col),mycard(texture)
{

}


bool card::operator==(card const & other) const
{
	return number == other.number || color == other.color || color == wild || other.color == wild;

}
bool card::operator!=(card const & other) const
{
	return !(*this == other) ;
}

