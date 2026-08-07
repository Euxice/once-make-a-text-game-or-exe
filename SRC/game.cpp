#include "GAME.h"
#include "Scene main.h"
//#include "Scene main.h"
//#define SDL_MAIN_HANDLED
Game::Game()
{

}

Game::~Game()
{
	clean();
}

void Game::run()
{
	while (isRunning)
	{

		auto fs = SDL_GetTicks();

		SDL_Event event;
		//创建循环持续运行说是
		handleevent(&event);

		////拆分下列，独立封装为三个函数
		//currentScene->update();
		////清空
		//SDL_RenderClear(r);


		//currentScene->render();
		////更新
		//SDL_RenderPresent(r);
		update(deltaTime);
		render();

		auto fe = SDL_GetTicks();
		auto diff = fe - fs;
		if (diff < frameTime)
		{
			SDL_Delay(frameTime - diff);
			deltaTime = frameTime / 1000.0f;
		}
		else
		{
			deltaTime = diff / 1000.0f;
		}




	}




}

void Game::init()
{
	frameTime = 1000 / FPS;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "init  SDL_Error:%s\n ", SDL_GetError());
		isRunning = false;
	}

	//创窗口
	w = SDL_CreateWindow("Concentration can achieve everything.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ww, wh, SDL_WINDOW_SHOWN);
	if (w == nullptr)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "window SDL_Error:%s\n ", SDL_GetError());
		isRunning = false;
	}
	//渲染
	r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
	if (r == nullptr)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "renderer SDL_Error:%s\n ", SDL_GetError());
		isRunning = false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "img Error : %s\n", IMG_GetError());
		isRunning = false;
	}






	currentScene = new Scenemain();
	currentScene->init();
} 

void Game::clean()
{
	if (currentScene != nullptr)
	{
		currentScene->clean();
		delete currentScene;
	}


	IMG_Quit();

	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);
	SDL_Quit();


}

void Game::changeScene(Scene* scene)// 更换场景
{
	if (currentScene != nullptr)
	{
		currentScene->clean();
		delete currentScene;
	}
	currentScene = scene;
	currentScene->init();
}

void Game::handleevent(SDL_Event* event)
{
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT)//退出
		{
			isRunning = false;
		}
		currentScene->handleEvents(event);




	}

}

void Game::update(float deltaTime)
{
	currentScene->update(deltaTime);

}

void Game::render()
{
	SDL_RenderClear(r);


	currentScene->render();
	//更新
	SDL_RenderPresent(r);

}
