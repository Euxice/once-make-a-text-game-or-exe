#ifndef GAME_H
#define GAME_H
#define SDL_MAIN_HANDLED

#include "Scene.h"
//#include "Scene main.h"
class Game {
public:
	//¾²Ì¬
	static Game& getInstance() {
		static Game instance;
		return instance;
	}
	~Game();
	void run();
	void init();
	void clean();
	void changeScene(Scene* scene);
	void handleevent(SDL_Event* event);
	void update(float deltaTime);
	void render();

	SDL_Window* getWindow() { return w; }
	SDL_Renderer* getRenderer() { return r; }
	int getWindowWidth() { return ww; }
	int getWindowHeight() { return wh; }



private:
	Game();

	Game(const Game&) = delete;
	Game& operater(const Game&) = delete;



	bool isRunning = true;
	Scene* currentScene = nullptr;
	SDL_Window* w = nullptr;
	SDL_Renderer* r = nullptr;
	int ww = 900;
	int wh = 800;
	int FPS = 60;
	Uint32 frameTime;
	float deltaTime;

};



#endif