#pragma once
#include "Input.h"
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

class Scene;

class Application2D : public aie::Application {
public:

	Application2D();
	
	virtual ~Application2D();



	aie::Renderer2D* getRenderer();

	virtual void update(float deltaTime);

	float getDeltaTime();

	virtual void draw();

	virtual bool startup();
	virtual void shutdown();

	


protected:

	Scene* splashScreenScene;
	Scene* gameScene;
	Scene* currentScene;
	aie::Input* input;
	aie::Renderer2D* renderer;

	float m_cameraX, m_cameraY;
	float deltaTime;
};



//25c513 (green)
//FF0000 (red)
//0026FF (blue)
//FF00DC (pink)