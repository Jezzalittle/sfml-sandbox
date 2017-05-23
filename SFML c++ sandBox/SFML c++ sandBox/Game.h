#pragma once
#include <SFML/Graphics.hpp>
class Blocks;
class LightBox;
class App;

class Game
{
public:	
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* a_window);
	void Start();


	int getWidth();
	int getHeigth();

	std::vector < Blocks* > GetBoxArray();

	int getAmountOfBlocks();

	Game(App* app);
	~Game();

private:
	sf::Text text;
	sf::Font font;
	int edgeCount;
	sf::Vector2f tl, tr, bl, br;
	bool once;
	sf::RenderWindow* rw;
	std::vector < Blocks* > boxArray;
	int width;
	int height;
	int amountOfBlocks;
	App* app;
	LightBox* lightbox;


};

