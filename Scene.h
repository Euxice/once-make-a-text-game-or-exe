#ifndef SCENE_H
#define SCENE_H
#define SDL_MAIN_HANDLED
//定义接口
#include "CMakeproject1.h"
//#include "Scene main.h"
class Scene {
public:
	Scene() = default;
	virtual ~Scene() = default;//                 必须写明虚析构

	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;
	virtual void clean() = 0;
	virtual void handleEvents(SDL_Event* event) = 0;




};
















#endif // SCENE_H