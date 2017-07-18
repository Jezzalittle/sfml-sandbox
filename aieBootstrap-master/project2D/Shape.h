#include "GameObject.h"

#pragma once
class Shape : GameObject
{
public:
	Shape();
	Shape(std::vector<Vector2> verts);
	Shape(Vector2 tl, Vector2 tr, Vector2 br, Vector2 bl);



	void addVetex(Vector2 v2);
	std::vector < Vector2 >  getVertex();

	void Draw(aie::Renderer2D * renderer);
	void Update(float deltaTime);

	Vector2 GetMiddle();

	~Shape();
private:

	Vector2 middle;
	std::vector < Vector2 > vertexArr;
	aie::Texture* texture;
};

