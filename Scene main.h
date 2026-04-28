#ifndef SCENE_MAIN_H
#define SCENE_MAIN_H
#define SDL_MAIN_HANDLED

#include "Scene.h"
#include "object.h"
#include <SDL.h>

class Game;


class Scenemain :public Scene {
public:
	Scenemain();
	~Scenemain();


	void update(float deltaTime) override;
	void render() override;
	void handleEvents(SDL_Event* event) override;//ÊÂ¼þ
	void init() override;
	void clean() override;

	void keyboardControl(float deltaTime);

	void sP();


private:
	
	Game& game;
	player a;
};







#endif // SCENE_MAIN_H