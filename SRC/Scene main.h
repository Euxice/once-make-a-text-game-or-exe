#ifndef SCENE_MAIN_H
#define SCENE_MAIN_H
#define SDL_MAIN_HANDLED

#include "Scene.h"
#include "object.h"
#include <SDL.h>
#include <list>

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
	void e1move(float deltaTime);

	void emove_time(float deltaTime);


	void sP();
	void eP();

	void ee1p(float deltaTime);

	void ae1p();
	void uppb(float deltaTime);
	void rpb();

	void emm();

	void eppb(float deltaTime);

	//int time();

private:
	
	Game& game;
	player a;
	em ae1;


	pb pbtl;
	eb eeb1;
	eb eeb2;
	int aaa = 0;
	int ee = 0;

	std::list<em*>aee1;

	std::list<pb*>ppb;
	std::list<eb*>eeb;
};







#endif // SCENE_MAIN_H