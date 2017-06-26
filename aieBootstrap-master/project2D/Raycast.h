#pragma once
#include "Vector2.h"
#include <iostream>
#include <vector>
#include "Shape.h"


class Raycast : GameObject
{
public:
	
	Raycast();
	Raycast(Vector2 p1, Vector2 p2);
	Vector2 beginingPos;
	Vector2 endingPos;
	
	void Draw(aie::Renderer2D * renderer);

	float GetDegree();



	Vector2 LineIntersectionPoint(Raycast* ray2);
	bool LineSegmentIntersectionPoint(Vector2 pos1, Vector2 pos2, Vector2& intersectionPoint);

	void CheckForRaycollision(std::vector <Shape*> shapeArr);

	

private:
	Vector2 Difference;
	bool hit;

};

