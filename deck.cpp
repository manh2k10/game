#define DECK_SIZE 108

 #include"deck.h"
deck::deck()
{
	ptr_deck = new card[DECK_SIZE];
	size = 0;


}
ultis graphics;
void deck::create()
{
   card tmp;


    for(int i=wild;i<=yellow;i++)
    {
        string s;

        if(i==wild)
        {
            for(int j=0;j<4;j++)
            {
                tmp.number=13;
                tmp.color=wild;
                tmp.mycard=graphics.loadtexture("images/wild13.png");
                ptr_deck[size]=tmp;size++;
                tmp.number=14;
                tmp.color=wild;
                tmp.mycard=graphics.loadtexture("images/wild14.png");
                ptr_deck[size]=tmp;
                size++;
            }

        }
        else for(int j=0;j<=12;j++)
        {
            switch(i)
            {
                 case red:
                     {
                          s="images/red.png";
                          if(j<10) s.insert(10,1,char(j+48));
                          else
                            switch(j)
                          {
                              case 10:s.insert(10,"10");break;
                              case 11:s.insert(10,"11");break;
                              case 12:s.insert(10,"12");break;
                          }
                          tmp.number=j;
                          tmp.color=red;

                          break;
                     }
                case blue:
                     {

                          s="images/blue.png";
                          if(j<10) s.insert(11,1,char(j+48));
                          else
                            switch(j)
                          {
                              case 10:s.insert(11,"10");break;
                              case 11:s.insert(11,"11");break;
                              case 12:s.insert(11,"12");break;
                          }
                          tmp.number=j;
                          tmp.color=blue;

                          break;
                     }
                case green:
                     {
                          s="images/green.png";
                          if(j<10) s.insert(12,1,char(j+48));
                          else
                            switch(j)
                          {
                              case 10:s.insert(12,"10");break;
                              case 11:s.insert(12,"11");break;
                              case 12:s.insert(12,"12");break;
                          }
                          tmp.number=j;
                          tmp.color=green;


                          break;
                     }
                case yellow:
                     {
                          s="images/yellow.png";
                          if(j<10) s.insert(13,1,char(j+48));
                          else
                            switch(j)
                          {
                              case 10:s.insert(13,"10");break;
                              case 11:s.insert(13,"11");break;
                              case 12:s.insert(13,"12");break;
                          }
                          tmp.number=j;

                          break;
                     }


            }
            tmp.mycard=graphics.loadtexture(s);
            if(j==0)
                 for(int a=0;a<2;a++)
                 {
                   ptr_deck[size]=tmp;
                   size++;
                 }
            else
            {
                 ptr_deck[size]=tmp;
                 size++;
            }


        }
    }
}

deck::deck(const deck & other)
{
	copy(other);
}


const deck & deck::operator= (const deck & other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}



deck::~deck()
{
	clear();
}




void deck::shuffle()
{
    srand(time(NULL));
	card * temp_deck = new card[size];
	for (int i =0; i<size; i++)
	{
		temp_deck[i] = ptr_deck[i];
	}


	int temp_size = size;
	int temp_pos;
	int pos;
	for (int i = 0 ; i <size; i++ )
	{
		// randomly find a position in temp_deck
		// change the seed , so randomized number is different each time
		pos = rand() % temp_size;
		//assign random element to deck[i]
		ptr_deck[i] = temp_deck[pos];

		// removing element from temp_deck (O(n) to shift)
		temp_size--;
		for (temp_pos = pos ; temp_pos < temp_size ; temp_pos++)
		{
			temp_deck[temp_pos] = temp_deck[temp_pos+1];
		}
	}

	delete [] temp_deck;



}
card deck::draw()
{
	if (size <= 0)
	{
		// do this inside gameplay
		//recreate
		//must take into account cards in player's hands
		return card();
	}
	card temp_card = ptr_deck[size-1];
	size--;
	return temp_card;
}


int deck::add_card(card temp_card)
{
	// O(1) insert
	if(size < DECK_SIZE)
	{
		ptr_deck[size] = temp_card;
		size++;
		return 0;
	}
	else
		return -1;
}


void deck::quick_shuffle()
{

	int pos;
	srand(time(NULL));
	int temp_size = size-1;
	card temp_card;
	while(temp_size > 0 )
	{
		//generate random
		// change the seed , so randomized number is different each time
		pos = rand() % temp_size;
		// swap elements
		temp_card = ptr_deck[temp_size];
		ptr_deck[temp_size] = ptr_deck[pos];
		ptr_deck[pos] = temp_card;
		// reduce size by 1
		temp_size--;
	}

}


void deck::copy(const deck & other)
{
	size = other.size;
	ptr_deck = new card[size];
	for (int i =0 ; i < size ; i++)
	{
		ptr_deck[i] = other.ptr_deck[i];
	}
}


void deck::clear()
{
	delete []ptr_deck;
	ptr_deck = NULL;
	size = 0;
}


int deck::get_size()
{
	return size;
}

