#pragma once
#include "Scene.h"
class SplashScreen : public Scene
{
public:
	SplashScreen();
	~SplashScreen();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* r2d);
	void StartUp();
	void ShutDown();


};

