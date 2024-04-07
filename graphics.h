


#include<iostream>
#include<SDL_image.h>
#include<SDL.h>
#include"def.h"
using namespace std;
class ultis
{
  public:
        SDL_Window* window;
        SDL_Renderer* renderer;
        void SDLInit();
        void close();
        void waitkeypressed();
        SDL_Texture* loadtexture(string path);
        bool inside(int &x,int &y,SDL_Rect rect);
        void free(SDL_Texture* &texture);
        void renderTexture(SDL_Texture *texture, int x, int y,int w,int h);
        void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
        SDL_Rect toado(SDL_Texture *texture, int x, int y);

};




