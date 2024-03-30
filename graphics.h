#ifndef SDL_ULTIS_H
#define SDL_ULTIS_H

#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"def.h"
using namespace std;
struct ultis
{

       /* void SDLInit();
        void close();
        void waitkeypressed();
        SDL_Texture* loadtexture(string path);
        bool inside(int &x,int &y,SDL_Rect rect);
        void free(SDL_Texture* &texture);
        void renderTexture(SDL_Texture *texture, int x, int y);
        void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
*/
    SDL_Window* window;
    SDL_Renderer* renderer;
    void SDLInit()
{
   SDL_Init(SDL_INIT_EVERYTHING);
   window =SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);

   renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

   SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, width, height);

}
void close()
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
SDL_Texture* loadtexture(string path)
{
    SDL_Texture* newtexture=nullptr;
    newtexture =IMG_LoadTexture(renderer,path.c_str());
        if(newtexture==nullptr)
            cout<<SDL_GetError()<<endl;

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
void free(SDL_Texture* &texture)
{
    SDL_DestroyTexture(texture);
    texture=nullptr;
}
void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        dest.w = src->w;
        dest.h = src->h;

        SDL_RenderCopy(renderer, texture, src, &dest);
    }
void renderTexture(SDL_Texture *texture, int x, int y,int w,int h)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        dest.w/=w;
        dest.h/=h;
        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }
SDL_Rect toado(SDL_Texture *texture, int x, int y)
{

        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        return dest;
}



};

#endif