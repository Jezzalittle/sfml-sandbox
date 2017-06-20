#include "GameObject.h"

#pragma once
class Shape : GameObject
{
public:
	Shape();
	Shape(Vector2 tl, Vector2 rl, Vector2 bl, Vector2 br);
	void addVetex(Vector2 v2);
	std::vector < Vector2 >  getVertex();

	void Draw(aie::Renderer2D * renderer);
	void Update(float deltaTime);

	Vector2 GetMiddle();

	~Shape();
private:

	Vector2 middle;
	std::vector < Vector2 > vertexArr;

};

