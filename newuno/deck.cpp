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
   for(int i=0;i<=4;i++)
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
                         tmp.color=yellow;
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
		size+=1;
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
void deck::animateDeal(SDL_Texture* texture1,SDL_Texture* texture2, SDL_Texture* background, ultis graphics, int startX, int startY, int endX, int endY, player temp_player[]) {
    int frames = 10; // Số khung hình trong quá trình di chuyển
    int currentFrame = 0;
   // int endx=550;

    int deltaX = (endX - startX) / frames;
    int deltaY = (endY-startY) / frames;

    int currentX = startX;
    int currentY = startY;

    // Tạo hai bộ đệm riêng biệt
    SDL_Texture* bufferTexture1 = SDL_CreateTexture(graphics.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    SDL_Texture* bufferTexture2 = SDL_CreateTexture(graphics.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

    // Chọn bộ đệm hiển thị ban đầu là bufferTexture1
    SDL_Texture* displayBuffer = bufferTexture1;

    while (currentFrame <= frames) {
        // Chuyển đổi bộ đệm hiển thị
        if (displayBuffer == bufferTexture1) {
            displayBuffer = bufferTexture2;
        } else {
            displayBuffer = bufferTexture1;
        }

        // Chọn bộ đệm làm mục tiêu vẽ
        SDL_SetRenderTarget(graphics.renderer, displayBuffer);

        // Xóa bộ đệm
        SDL_RenderClear(graphics.renderer);

        // Vẽ các phần tử cố định lên bộ đệm
        SDL_RenderCopy(graphics.renderer, background, NULL, NULL);
         graphics.renderTexture(texture1,300,250,6,6);
        temp_player[0].print(graphics,460,texture1,true);
        temp_player[1].print(graphics,40,texture1,false);

        // Vẽ phần tử di chuyển lên bộ đệm
        graphics.renderTexture(texture2, currentX, currentY, 6, 6);

        // Chuyển đổi bộ đệm hiển thị lên màn hình
        SDL_SetRenderTarget(graphics.renderer, NULL);
        SDL_RenderCopy(graphics.renderer, displayBuffer, NULL, NULL);
        SDL_RenderPresent(graphics.renderer);

        currentX += deltaX;
        currentY += deltaY;

        currentFrame++;

        SDL_Delay(10); // Đợi một thời gian ngắn giữa các khung hình
    }
    if(currentX!=endX||currentY!=endY)
    {
        if (displayBuffer == bufferTexture1) {
            displayBuffer = bufferTexture2;
        } else {
            displayBuffer = bufferTexture1;
        }

        // Chọn bộ đệm làm mục tiêu vẽ
        SDL_SetRenderTarget(graphics.renderer, displayBuffer);

        // Xóa bộ đệm
        SDL_RenderClear(graphics.renderer);

        // Vẽ các phần tử cố định lên bộ đệm
        SDL_RenderCopy(graphics.renderer, background, NULL, NULL);
         graphics.renderTexture(texture1,300,250,6,6);
        temp_player[0].print(graphics,460,texture1,true);
        temp_player[1].print(graphics,40,texture1,false);

        // Vẽ phần tử di chuyển lên bộ đệm
        graphics.renderTexture(texture2, endX, endY, 6, 6);

        // Chuyển đổi bộ đệm hiển thị lên màn hình
        SDL_SetRenderTarget(graphics.renderer, NULL);
        SDL_RenderCopy(graphics.renderer, displayBuffer, NULL, NULL);
        SDL_RenderPresent(graphics.renderer);
    }

    // Giải phóng bộ đệm
    SDL_DestroyTexture(bufferTexture1);
    SDL_DestroyTexture(bufferTexture2);
}
void deck::newclear()
{
    delete []ptr_deck;
	ptr_deck = new card[DECK_SIZE];
	size = 0;
}

