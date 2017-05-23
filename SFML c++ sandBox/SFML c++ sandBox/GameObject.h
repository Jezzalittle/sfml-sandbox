#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Game;

class GameObject 
{
public:
	GameObject(Game* a_app);
	GameObject();
	void Start();
	void Update(float deltaTime);
	void Draw(RenderWindow* renderer);

	~GameObject();

protected:
	Vector2f pos;
	Game* game;
};


