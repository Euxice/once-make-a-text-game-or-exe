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
	




	//emove_time(deltaTime); //    试制
	//e1move(deltaTime);
	uppb(deltaTime);
	//eppb(deltaTime);
	spawE();
	upE(deltaTime);
	upss(deltaTime);

	UpdatePlayer(deltaTime);





}

void Scenemain::UpdatePlayer(float deltaTime)
{
	if (isdead == true)
	{
		return;
	}
	if (a.he <= 0)
	{
		//todo game over
		isdead = true;
	}
	for (auto enemy : ye1)
	{
		SDL_Rect enn = {
			static_cast<int>(enemy->p.x),
			static_cast<int>(enemy->p.y),
			enemy->w,
			enemy->h
		};
		SDL_Rect paa = {
			static_cast<int>(a.position.x),
			static_cast<int>(a.position.y),
			a.width,
			a.height
		};
		if (SDL_HasIntersection(&paa, &enn))
		{
			a.he -= 1;
			enemy->he -= 1 ;
			

		}
	}

}

void Scenemain::render()
{
	ren();
	rpb();
	ae1p();
	rss();
	if (!isdead)
	{
		SDL_Rect aRect = { static_cast<int>(a.position.x),
			static_cast<int>(a.position.y),
			a.width,
			a.height };
	    SDL_RenderCopy(game.getRenderer(), a.texture, NULL, &aRect);
	}
	
	/*SDL_Rect eRect = { static_cast<int>(ae1.po.x),static_cast<int>(ae1.po.y),ae1.ewidth,ae1.eheight };
	SDL_RenderCopy(game.getRenderer(), ae1.t, NULL, &eRect);*/
	



}

void Scenemain::handleEvents(SDL_Event* event)
{




}

void Scenemain::init()
{
	std::random_device rd;
	gen = std::mt19937(rd());
	dis = std::uniform_real_distribution<float>(0.0f, 1.0f);
	auto r = dis(gen);



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
	

	eeb1.t = IMG_LoadTexture(game.getRenderer(), "D:/Text game/CMakeProject1/jpg & png/set eebp1 3.png");
	SDL_QueryTexture(eeb1.t, NULL, NULL, &eeb1.w, &eeb1.h);
	eeb1.w /= 20;
	eeb1.h /= 20;


	en1.t = IMG_LoadTexture(game.getRenderer(),"D:/Text game/CMakeProject1/jpg & png/en1.png");
	if (en1.t == nullptr)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "en1 t Error :%s", SDL_GetError());
	}
	SDL_QueryTexture(en1.t, NULL, NULL, &en1.w, &en1.h);
	en1.w /= 20;
	en1.h /= 20;

	eeb3.t = IMG_LoadTexture(game.getRenderer(), "D:/Text game/CMakeProject1/jpg & png/ser2 eeb2.png");
	if (eeb3.t == nullptr)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "eeb3 t Error :%s", SDL_GetError());

	}
	SDL_QueryTexture(eeb3.t, NULL, NULL, &eeb3.w, &eeb3.h);
	eeb3.w /= 20;
	eeb3.h /= 20;





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
	for (auto& pj : ye1)
	{
		if (pj != nullptr)
		{
			delete pj;
		}
		ye1.clear();
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
	if (eeb3.t != nullptr)
	{
		SDL_DestroyTexture(eeb3.t);
	}



}

void Scenemain::keyboardControl(float deltaTime)//可整合至player类中
{
	if (isdead == true)
	{
		return;
	}
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

void Scenemain::e1move(float deltaTime)
{
	long iii = 0;
	
	
	for (int m = 0; m < 10; m++)
	{
		
		if (ae1.po.x <= 620 && aaa%2!= 1)
		{
			ae1.po.x += ae1.speed * deltaTime;
			if (ae1.po.x > 620)
			{
				aaa += 1;
			}
			std::cout << iii;
			if (iii % 2 == 0)
			{
				ae1.po.y += ae1.speed * deltaTime/2;
			}
			

			iii++;
			std::cout << "|" << ae1.po.x << "|" << std::endl;

		}
		else if (ae1.po.x > 0 && aaa%2 == 1)
		{
			ae1.po.x -= ae1.speed * deltaTime;
			if (ae1.po.x < 0)
			{
				aaa += 1;
			}
			std::cout << iii;
			std::cout << "|" << ae1.po.x << "|" << std::endl;
			iii++;
			if (iii % 2 == 0)
			{
				ae1.po.y += ae1.speed * deltaTime/2;
			}
		}




		if (ae1.po.y > 770)
		{
			ae1.po.x = -50;
			ae1.po.y = -50;
			aaa = 0;
		}










	}
}

void Scenemain::emove_time(float deltaTime)
{
	int els = 0;
	int ecd = 300;
	auto ct = SDL_GetTicks();
	if (ct - els > ecd && ee < 5)
	{
		ee1p(deltaTime);
		//e1move(deltaTime);
		els = ct;
		std::cout << ee << std::endl;
	}
	for (auto it = aee1.begin(); it != aee1.end();)
	{
		long iii = 0;
		auto pj = *it;

		for (int m = 0; m < 10; m++)
		{

			if (pj->po.x <= 620 && aaa % 2 != 1)
			{
				pj->po.x += pj->speed * deltaTime;
				if (pj->po.x > 620)
				{
					aaa += 1;
				}
				std::cout << iii;
				if (iii % 2 == 0)
				{
					pj->po.y += pj->speed * deltaTime / 2;
				}


				iii++;
				std::cout << "|" << pj->po.x << "|" << std::endl;

			}
			else if (pj->po.x > 0 && aaa % 2 == 1)
			{
				pj->po.x -= pj->speed * deltaTime;
				if (pj->po.x < 0)
				{
					aaa += 1;
				}
				std::cout << iii;
				std::cout << "|" << pj->po.x << "|" << std::endl;
				iii++;
				if (iii % 2 == 0)
				{
					pj->po.y += pj->speed * deltaTime / 2;
				}
			}




			if (pj->po.y > 770)
			{
				pj->po.x = -50;
				pj->po.y = -50;
				aaa = 0;
			}
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
	pj->p.y = ae1.po.y+30;
	eeb.push_back(pj);
}

void Scenemain::ee1p(float deltaTime)
{
	auto pj = new em(ae1);
	pj->po.x = -50;
	pj->po.y = 50;
	aee1.push_back(pj);
	ee += 1;
	//e1move(deltaTime);




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
			bool hit = false;
			for (auto eo : ye1)
			{
				SDL_Rect eR = {
					static_cast<int>(eo->p.x),
					static_cast<int>(eo->p.y),
					eo->w,
					eo->h


				};
				SDL_Rect bp = {
					static_cast<int>(pj->p.x),
					static_cast<int>(pj->p.y),
					pj->w,
					pj->h
				};
				if (SDL_HasIntersection(&eR, &bp))
				{
					eo->he -= pj->het;
					delete pj;
					it = ppb.erase(it);
					hit = true;
					break;
				}
			}
			if (!hit)
			{
				++it;
			}
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

void Scenemain::emm()
{
	for (auto pj : aee1)
	{
		SDL_Rect ar = {
			static_cast<int>(pj->po.x),
			static_cast<int>(pj->po.y),
			pj->ewidth,
			pj->eheight
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
		if (pj->p.y - m > 800 && !isdead)
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

void Scenemain::spawE()
{
	if (dis(gen) > 1 / 60.0f)
	{
		return;
	}
	En* e = new En(en1);
	e->p.x = dis(gen) * (game.getWindowWidth() - e->w+30)-230;
	e->p.y = - e->h;
	ye1.push_back(e);



}

void Scenemain::upE(float deltaTime)
{
	
	auto cT = SDL_GetTicks();
	for (auto it = ye1.begin(); it != ye1.end();)
	{

		auto pj = *it;
		pj->p.y += pj->s * deltaTime;

		if (pj->p.y >800)
		{
			delete pj;
			it = ye1.erase(it);
		}
		else {
			if (cT-pj->ls>pj->cd && isdead == false)
			{
				shootE(pj);
				pj->ls = cT;
			}
			if (pj->he <= 0)
			{
				enemyExplode(pj);
				it = ye1.erase(it);
			}
			else
			{
				++it;
			}

		}
	}








}

void Scenemain::ren()
{
	for (auto pj : ye1)
	{
		SDL_Rect er = {
			static_cast<int>(pj->p.x),
			static_cast<int>(pj->p.y),
			pj->w,
			pj->h

		};
		SDL_RenderCopy(game.getRenderer(), pj->t, NULL, &er);
	}




}

void Scenemain::shootE(En* en1 )
{
	auto pj = new SPe(eeb3);
	pj->p.x = en1->p.x + en1->w / 2 - pj->w / 2;
	pj->p.y = en1->p.y + en1->h / 2 - pj->h / 2;
	pj->d = getc(en1);// 矢量确认


	ss.push_back(pj);


}

SDL_FPoint Scenemain::getc(En* en1)//方向，向量
{
	auto x = (a.position.x + a.width / 2) - (en1->p.x + en1->w / 2);
	auto y = (a.position.y + a.height / 2) - (en1->p.y + en1->h / 2);
	auto len = sqrt(x * x + y * y);
	x /= len;
	y /= len;

	return SDL_FPoint(x,y);
}

void Scenemain::upss(float deltaTime)
{
	auto margin = 32;
	for (auto it = ss.begin(); it != ss.end();)
	{
		auto pj = *it;
		pj->p.x += pj->s * pj->d.x * deltaTime;
		pj->p.y += pj->s * pj->d.y * deltaTime;
		if (pj->p.y > 800||
			pj->p.y<-margin||
			pj->p.x<-margin||
			pj->p.x>620+margin)
		{
			delete pj;
			it = ss.erase(it);
		}
		else {
			SDL_Rect pjbr = {
				static_cast<int>(pj->p.x),
				static_cast<int>(pj->p.y),
				pj->w,
				pj->h
			};
			SDL_Rect ppr = {
				static_cast<int>(a.position.x),
				static_cast<int>(a.position.y),
				a.width,
				a.height
			};
			if (SDL_HasIntersection(&pjbr, &ppr) )
			{
				a.he -= pj->het;
				delete pj;
				it = ss.erase(it);
			}
			else
			{
				++it;
			}
		}
	}




}

void Scenemain::rss()
{
	for (auto pj : ss)
	{
		SDL_Rect pjr = {
			static_cast<int>(pj->p.x),
			static_cast<int>(pj->p.y),
			pj->w,
			pj->h
		};
		//SDL_RenderCopy(game.getRenderer(), pj->t, NULL, &pjr);
		float a = atan2(pj->d.y, pj->d.x) * 180 / M_PI - 90;// 由于两者之间角度协议不同，所以需要的角度比计算角小90°
		SDL_RenderCopyEx(game.getRenderer(), pj->t, NULL, &pjr, a, NULL, SDL_FLIP_NONE);
	}



}

void Scenemain::enemyExplode(En* enemy)
{
	delete enemy;





}

//int Scenemain::time()
//{
//	if (ae1.po.x == 620)
//	{
//		aaa = 1;
//		std::cout << "aaa" << aaa << std::endl;
//		return aaa;
//	}
//	else {
//		return aaa;
//	}
//	
//}




