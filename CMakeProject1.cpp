// CMakeProject1.cpp: 定义应用程序的入口点。
//
#define SDL_MAIN_HANDLED        //解决1120，2019问题 ，main在sdl里面有重复函数

#include "CMakeProject1.h"
#include "GAME.h"


using namespace std;

int main()
{
	Game& game = Game::getInstance();
	game.init();
	game.run();

	return 0;
}
