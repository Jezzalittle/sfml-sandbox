#pragma once
#include "GameObject.h"

class Blocks : GameObject
{
public:


	Blocks(Vector2f a_tl, Vector2f a_tr, Vector2f a_bl, Vector2f a_br);
	
	void Start();

	void Update(float deltaTime);

	void Draw(RenderWindow * renderer);



	~Blocks();

	std::vector <Vector2f> vertexArr;

	Vector2f tl, tr, bl, br;

private:

	ConvexShape box;

};

