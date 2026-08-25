#ifndef SCENE_MAIN_H
#define SCENE_MAIN_H
#define SDL_MAIN_HANDLED

#include "Scene.h"
#include "object.h"
#include <SDL.h>
#include <list>
#include <random>// 随机19937算法主要
class Game;


class Scenemain :public Scene {
public:
	Scenemain();
	~Scenemain();


	void update(float deltaTime) override;
	void render() override;
	void handleEvents(SDL_Event* event) override;//事件
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




	void spawE();
	void upE(float deltaTime);
	void ren();


	void shootE(En *en1);
	SDL_FPoint getc(En*en1);
	void upss(float deltaTime);
	void rss();

private:
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_real_distribution<float>dis;




	Game& game;
	player a;
	em ae1;
	En en1;



	SPe eeb3;



	pb pbtl;
	eb eeb1;
	eb eeb2;
	int aaa = 0;
	int ee = 0;

	std::list<em*>aee1;
	std::list<En*>ye1;

	std::list<SPe*>ss;


	std::list<pb*>ppb;
	std::list<eb*>eeb;
};







#endif // SCENE_MAIN_H