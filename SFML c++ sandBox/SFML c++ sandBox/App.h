#pragma once
#include <SFML/Graphics.hpp>
#include "wtypes.h"
#include "Game.h"

using namespace sf;

class App
{
public:

	App();
	void execute();
	~App();
	int horizontal;
	int vertical;

private:

	void Start();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* a_window);
	void Shutdown();

	void GetDesktopResolution(int& horizontal, int& vertical);

	float deltaTime;
	Game*  game;
	const float FPS = 60.0f;
	RenderWindow window;

};

