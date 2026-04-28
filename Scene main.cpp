#include "Scene main.h"
#include "GAME.h"
//#include <SDL.h>
//#include <SDL_image.h>
Scenemain::Scenemain():game(Game::getInstance())
{
}

Scenemain::~Scenemain()
{
}

void Scenemain::update(float deltaTime)
{ 
	keyboardControl(deltaTime);


}

void Scenemain::render()
{
	SDL_Rect aRect = { static_cast<int>(a.position.x),static_cast<int>(a.position.y),a.width,a.height };
	SDL_RenderCopy(game.getRenderer(), a.texture, NULL, &aRect);
}

void Scenemain::handleEvents(SDL_Event* event)
{




}

void Scenemain::init()
{
	a.texture = IMG_LoadTexture(game.getRenderer(), "D:/Text game/CMakeProject1/jpg & png/set1.png");
	if (a.texture == nullptr)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "player te Error: %s", SDL_GetError());
	}
	SDL_QueryTexture(a.texture, NULL, NULL, &a.width, &a.height);
	a.width /= 10;
	a.height /= 10;
	a.position.x = game.getWindowWidth() / 2 - a.width / 2 - 200;
	a.position.y = game.getWindowHeight() - a.height;
}

void Scenemain::clean()
{
	if (a.texture != nullptr)
	{
		SDL_DestroyTexture(a.texture);
	}
}

void Scenemain::keyboardControl(float deltaTime)//可整合至player类中
{
	auto k = SDL_GetKeyboardState(NULL);
	if (k[SDL_SCANCODE_W])
	{
		a.position.y -= deltaTime * a.speed;
		if (a.position.y < 0)
		{
			a.position.y = 0;
		}
	}
	if (k[SDL_SCANCODE_S ])
	{
		a.position.y += deltaTime * a.speed;
		if (a.position.y > 720)
		{
			a.position.y = 720;
		}

	}
	if (k[SDL_SCANCODE_A])
	{
		a.position.x -= deltaTime * a.speed;
		if (a.position.x < 0)
		{
			a.position.x = 0;
		}
	}
	if (k[SDL_SCANCODE_D])
	{
		a.position.x += deltaTime * a.speed;
		if (a.position.x > 620)
		{
			a.position.x = 620;
		}
	}

	//子弹控制
	if (k[SDL_SCANCODE_J])
	{
		auto ct = SDL_GetTicks();
		if (ct - a.ls > a.cd)
		{
			sP();
			a.ls = ct;
		}
	}


	
}

void Scenemain::sP()
{
}




