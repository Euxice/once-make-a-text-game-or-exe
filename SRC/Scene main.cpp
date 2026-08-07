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
	uppb(deltaTime);
	eppb(deltaTime);
}

void Scenemain::render()
{
	
	rpb();
	ae1p();
	SDL_Rect aRect = { static_cast<int>(a.position.x),static_cast<int>(a.position.y),a.width,a.height };
	SDL_RenderCopy(game.getRenderer(), a.texture, NULL, &aRect);
	SDL_Rect eRect = { static_cast<int>(ae1.po.x),static_cast<int>(ae1.po.y),ae1.ewidth,ae1.eheight };
	SDL_RenderCopy(game.getRenderer(), ae1.t, NULL, &eRect);
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

	//模板
	pbtl.t = IMG_LoadTexture(game.getRenderer(), "D:/Text game/CMakeProject1/jpg & png/set2.png");
	SDL_QueryTexture(pbtl.t,NULL,NULL,&pbtl.w,&pbtl.h);
	pbtl.w /= 20;
	pbtl.h /= 20;

	ae1.t = IMG_LoadTexture(game.getRenderer(), "D:/Text game/CMakeProject1/jpg & png/set eeb1 3.png");
	if (ae1.t == nullptr)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "enemy te Error: %s", SDL_GetError());
	}
	SDL_QueryTexture(ae1.t, NULL, NULL, &ae1.ewidth, &ae1.eheight);
	ae1.ewidth /= 10;
	ae1.eheight /= 10;
	ae1.po.x = game.getWindowWidth() / 2 - ae1.ewidth / 2 - 200;
	ae1.po.y = ae1.eheight;

	eeb1.t = IMG_LoadTexture(game.getRenderer(), "D:/Text game/CMakeProject1/jpg & png/set eebp1 3.png");
	SDL_QueryTexture(eeb1.t, NULL, NULL, &eeb1.w, &eeb1.h);
	eeb1.w /= 20;
	eeb1.h /= 20;








}

void Scenemain::clean()
{
	for (auto& pj : ppb)
	{
		if (pj != nullptr)
		{
			delete pj;
		}
		ppb.clear();
	}
	if (a.texture != nullptr)
	{
		SDL_DestroyTexture(a.texture);
	}
	if (pbtl.t != nullptr)
	{
		SDL_DestroyTexture(pbtl.t);
	}
	if (ae1.t != nullptr)
	{
		SDL_DestroyTexture(ae1.t);
	}
	if (eeb1.t != nullptr)
	{
		SDL_DestroyTexture(eeb1.t);
	}
}

void Scenemain::keyboardControl(float deltaTime)//可整合至player类中
{
	auto k = SDL_GetKeyboardState(NULL);
	if (k[SDL_SCANCODE_W])
	{
		if (k[SDL_SCANCODE_LSHIFT])
		{
			a.position.y -= deltaTime * a.speed * 2;
		}
		else
		{
			a.position.y -= deltaTime * a.speed;
		}
		    
		
		if (a.position.y < 0)
		{
			a.position.y = 0;
		}
	}
	if (k[SDL_SCANCODE_S ])
	{
		if (k[SDL_SCANCODE_LSHIFT])
		{
			a.position.y += deltaTime * a.speed * 2;
		}
		else
		{
			a.position.y += deltaTime * a.speed;
		}
		//a.position.y += deltaTime * a.speed;
		if (a.position.y > 720)
		{
			a.position.y = 720;
		}

	}
	if (k[SDL_SCANCODE_A])
	{
		if (k[SDL_SCANCODE_LSHIFT])
		{
			a.position.x -= deltaTime * a.speed * 2;
		}
		else
		{
			a.position.x -= deltaTime * a.speed;
		}
		if (a.position.x < 0)
		{
			a.position.x = 0;
		}
	}
	if (k[SDL_SCANCODE_D])
	{
		if (k[SDL_SCANCODE_LSHIFT])
		{
			a.position.x += deltaTime * a.speed * 2;
		}
		else
		{
			a.position.x += deltaTime * a.speed;

		}
		
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
	auto pj = new pb(pbtl);
	pj->p.x = a.position.x + a.width/2 -  pj->w / 2;
	pj->p.y = a.position.y;
	ppb.push_back(pj);

}

void Scenemain::eP()
{
	auto pj = new eb(eeb1);
	pj->p.x = ae1.po.x + ae1.ewidth/2 - pj->w / 2;
	pj->p.y = ae1.eheight+30;
	eeb.push_back(pj);
}

void Scenemain::ae1p()
{
	for (auto pj : eeb)
	{
		SDL_Rect ar = {
			static_cast<int>(pj->p.x),
			static_cast<int>(pj->p.y),
			pj->w,
			pj->h
		};
		SDL_RenderCopy(game.getRenderer(), pj->t, NULL, &ar);
	}
	
}

void Scenemain::uppb(float deltaTime)
{

	for (auto it = ppb.begin(); it != ppb.end();)
	{
		int margin = 32;
		auto pj = *it;
		pj->p.y -= pj->s*deltaTime;
		if (pj->p.y + margin < 0)
		{
			delete pj;
			it = ppb.erase(it);
		}
		else
		{
			++it;
		}
	
	}
}

void Scenemain::rpb()
{
	for (auto pj : ppb)
	{
		SDL_Rect ar = {
			static_cast<int>(pj->p.x),
			static_cast<int>(pj->p.y),
			pj->w,
			pj->h
		};
		SDL_RenderCopy(game.getRenderer(), pj->t, NULL, &ar);
	}



}

void Scenemain::eppb(float deltaTime)
{
	
	auto ct = SDL_GetTicks();
	if (ct - ae1.ls > ae1.cd)
	{
		eP();
		ae1.ls = ct;
	}

	for (auto it = eeb.begin(); it != eeb.end();)
	{
		int m = 10;
		auto pj = *it;
		pj->p.y += pj->s * deltaTime;
		if (pj->p.y - m > 800)
		{
			delete pj;
			it = eeb.erase(it);
		}
		else
		{
			++it;
		}
	}

}




