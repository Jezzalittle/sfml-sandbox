#pragma once
#include "Application2D.h"
#include <iostream>

class Scene 
{
public:

	Scene();
	~Scene();

	std::string GetSceneName();

	virtual	void Update(float deltaTime);
	virtual void Draw(aie::Renderer2D* r2d);
	virtual void StartUp();
	virtual void ShutDown();


protected:
	std::string nameOfScene;
};

