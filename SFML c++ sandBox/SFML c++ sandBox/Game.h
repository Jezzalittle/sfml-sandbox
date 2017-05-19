#pragma once


class App;

class Game
{
public:
	
	void Update();
	void Draw();

	Game();
	~Game();

private:
	App* app;

};

