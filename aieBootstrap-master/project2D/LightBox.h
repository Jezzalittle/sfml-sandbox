#pragma once
#include "GameObject.h"


class Raycast;
class Shape;


class LightBox : public GameObject
{
public:
	LightBox();

	LightBox(Vector2 a_pos);

	

	void Draw(aie::Renderer2D * renderer);

	void Update(float deltaTime);

	std::vector<Raycast*> MakeRays(std::vector<Shape*> shapeArr);

	void sortArrayByRot(std::vector<Raycast*>& rayArr);

	std::vector<Shape*> sortShapes(std::vector<Shape*> shapesArr);

	void CleanUpArray(std::vector<Raycast*>& a_rayArr);

	void MakeLightTriangles(std::vector<Raycast*> a_rayArr);



	~LightBox();

private:
	aie::Input* input;
	Vector2 pos;
};

