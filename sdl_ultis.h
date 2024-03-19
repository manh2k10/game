#ifndef SDL_ULTIS_H
#define SDL_ULTIS_H

#include<iostream>
#include<SDL_image.h>
#include<SDL.h>

using namespace std;

void SDLError(ostream& os,const string &msg,bool fatal=false);
void SDLInit(SDL_Window* &window,SDL_Renderer* &renderer,const int &width,const int &height,const string &title);
void close(SDL_Window* &window,SDL_Renderer* &renderer);
void waitkeypressed();
SDL_Texture* loadtexture(string path,SDL_Renderer* &renderer);
bool inside(int &x,int &y,SDL_Rect rect);

#endif
