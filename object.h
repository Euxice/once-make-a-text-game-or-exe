#ifndef OBJECT_H
#define OBJECT_H
#include <SDL.h>

struct player {
	SDL_Texture* texture = nullptr;
	SDL_FPoint position = { 0,0 };
	int width = 0;
	int height = 0;
	int speed = 300;
	Uint32 cd = 500;
	Uint32 ls = 0;
};

struct pb {
	SDL_Texture* t = nullptr;
	SDL_FPoint p = { 0,0 };
	int w = 0;
	int h = 0;
	int s = 400;
};



struct em {
	SDL_Texture* t = nullptr;
	SDL_FPoint po = { 0,0 };
	int ewidth = 0;
	int eheight = 0;




};

struct eb {
	SDL_Texture* t = nullptr;
	SDL_FPoint p = { 0,0 };
	int w = 0;
	int h = 0;
	int s = 400;
};



















#endif // OBJECT_H