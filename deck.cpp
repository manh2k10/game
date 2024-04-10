#define DECK_SIZE 108

 #include"deck.h"
 #include"graphics.h"
deck::deck()
{
	ptr_deck = new card[DECK_SIZE];
	size = 0;


}

void deck::create( ultis mygraphics)
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
                tmp.mycard=mygraphics.loadtexture("images/wild13.png");
                ptr_deck[size]=tmp;size++;
                tmp.number=14;
                tmp.color=wild;
                tmp.mycard=mygraphics.loadtexture("images/wild14.png");
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
            tmp.mycard=mygraphics.loadtexture(s);
            if(tmp.mycard==nullptr)cout<<j<<endl;
            if(j!=0)
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
//hàm sao chép của lớp deck
deck::deck(const deck & other)
{
	copy(other);
}

//toán tử gán của lớp deck.
const deck & deck::operator= (const deck & other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}


//hàm hủy
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

		pos = rand() % temp_size;

		ptr_deck[i] = temp_deck[pos];


		temp_size--;
		for (temp_pos = pos ; temp_pos < temp_size ; temp_pos++)
		{
			temp_deck[temp_pos] = temp_deck[temp_pos+1];
		}
	}

	delete [] temp_deck;



}
//loại bỏ và trả về lá bài trên cùng của bộ bài.
card deck::draw()
{
	if (size <= 0)
	{

		return card();
	}
	card temp_card = ptr_deck[size-1];
	size--;
	return temp_card;
}

// thêm một lá bài mới vào bộ bài.
int deck::add_card(card temp_card)
{

	if(size < DECK_SIZE)
	{
		ptr_deck[size] = temp_card;
		size++;
		return 0;
	}
	else
		return -1;
}

// tron bai nhanh
void deck::quick_shuffle()
{

	int pos;
	srand(time(NULL));
	int temp_size = size-1;
	card temp_card;
	while(temp_size > 0 )
	{

		pos = rand() % temp_size;

		temp_card = ptr_deck[temp_size];
		ptr_deck[temp_size] = ptr_deck[pos];
		ptr_deck[pos] = temp_card;

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

