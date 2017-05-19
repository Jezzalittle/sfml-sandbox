#pragma once
#include <SFML/Graphics.hpp>
#include "wtypes.h"
#include "Game.h"

using namespace sf;

class App
{
public:

	App();
	void Start();
	void Update();
	void Draw();
	void StartUp();
	RenderWindow* GetWindow();

	float getDeltaTime();

	static App* m_instance;

	static App& instance()
	{
		return *m_instance;
	}


	~App();

private:

	void GetDesktopResolution(int& horizontal, int& vertical);

	float deltaTime;
	Game*  game;
	int horizontal;
	int vertical;
	const float FPS = 60.0f;
	RenderWindow window;

};

