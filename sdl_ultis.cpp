#include"sdl_ultis.h"




void SDLError(ostream& os,const string &msg,bool fatal)
{
    os<<msg<<SDL_GetError()<<endl;
    if(fatal)
    {
        SDL_Quit();
        exit(1);
    }
}
void SDLInit(SDL_Window* &window,SDL_Renderer* &renderer,const int &width,const int &height,const string &title)
{
   if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
        SDLError(cout,"123",true);
   window =SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
   if(window==nullptr)  SDLError(cout,"123",true);
   renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
   if(renderer==nullptr)  SDLError(cout,"123",true);
   SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, width, height);

}
void close(SDL_Window* &window,SDL_Renderer* &renderer)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
void waitkeypressed()
{
    SDL_Event e;
    while (true)
        {
           if ( SDL_WaitEvent(&e) != 0 &&(e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )return;
           SDL_Delay(100);
        }
 }
SDL_Texture* loadtexture(string path,SDL_Renderer* &renderer)
{
    SDL_Texture* newtexture=nullptr;
    SDL_Surface* surface=IMG_Load(path.c_str());
    if(surface==nullptr)
        cout<<"unable to load, image error"<<IMG_GetError()<<endl;
    else
    {
        newtexture =SDL_CreateTextureFromSurface(renderer,surface);
        if(newtexture==nullptr)
            cout<<SDL_GetError()<<endl;
        SDL_FreeSurface(surface);
    }
    return newtexture;
}
bool inside(int &x,int &y,SDL_Rect rect)
{
    bool Inside=true;

        // Chuột nằm bên trái nút
        if( x < rect.x )
        {
            Inside = false;
        }
        //Chuột ở bên phải nút
        else if( x > rect.x + rect.w)
        {
            Inside = false;
        }
        //Chuột lên trên nút
        else if( y < rect.y )
        {
            Inside = false;
        }
        //Chuột bên dưới nút
        else if( y > rect.y + rect.h )
        {
            Inside = false;
        }
    return Inside;
}
