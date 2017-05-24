#include "LightBox.h"
#include "Blocks.h"
#include "Game.h"
#include <vector>
#include <cmath>

#include <iostream>


Raycast::Raycast(Vector2f v2, float a_rot)
{
	pos = v2;
	rot = a_rot;
}

LightBox::LightBox(Game* a_game, Vector2f a_pos)
{
	game = a_game;
	pos = a_pos;
	light.setPosition((Vector2f)pos);
	light.setFillColor(sf::Color::Red);
	light.setSize(Vector2f(10, 10));
	drawLines = false;
}

LightBox::~LightBox() 
{
}

void Raycast::setRot(Vector2f vec)
{

}

bool Raycast::LineSegmentIntersectionPoint(Vector2f ls1, Vector2f le1, Vector2f ls2, Vector2f le2, Vector2f& intersectionPoint)
{

		// Get A,B,C of first line - points : ps1 to pe1
		float A1 = le1.y - ls1.y;
		float B1 = ls1.x - le1.x;
		float C1 = A1*ls1.x + B1*ls1.y;

		// Get A,B,C of second line - points : ps2 to pe2
		float A2 = le2.y - ls2.y;
		float B2 = ls2.x - le2.x;
		float C2 = A2*ls2.x + B2*ls2.y;

		// Get delta and check if the lines are parallel
		float delta = A1*B2 - A2*B1;
		if (delta == 0)
			return false;

		std::cout << " " << A2 << std::endl;


		// now return the Vector2 intersection point
		intersectionPoint = Vector2f((B2*C1 - B1*C2) / delta, (A1*C2 - A2*C1) / delta);

		Vector2f line2 = le2 - ls2;
		Vector2f centerOfLine2 = ls2 + ( line2 / 2.0f );

		float line2Magnitude = sqrt(line2.x*line2.x + line2.y*line2.y);

		Vector2f vecBetweenCenterAndIntersection = centerOfLine2 - intersectionPoint;

		if (sqrt(vecBetweenCenterAndIntersection.x*vecBetweenCenterAndIntersection.x + vecBetweenCenterAndIntersection.y*vecBetweenCenterAndIntersection.y) <= line2Magnitude / 2.0f)
		{
			return true;
		}
		

		return false;
}



Vector2f Raycast::LineIntersectionPoint(Vector2f ls1, Vector2f le1, Vector2f ls2, Vector2f le2)
{
	{
		// Get A,B,C of first line - points : ps1 to pe1
		float A1 = le1.y - ls1.y;
		float B1 = ls1.x - le1.x;
		float C1 = A1*ls1.x + B1*ls1.y;

		// Get A,B,C of second line - points : ps2 to pe2
		float A2 = le2.y - ls2.y;
		float B2 = ls2.x - le2.x;
		float C2 = A2*ls2.x + B2*ls2.y;

		// Get delta and check if the lines are parallel
		float delta = A1*B2 - A2*B1;
		if (delta == 0)
			return Vector2f(-1, -1);

		std::cout << " " << A2 << std::endl;
		// now return the Vector2 intersection point
		return Vector2f((B2*C1 - B1*C2) / delta, (A1*C2 - A2*C1) / delta);
	}
}



void LightBox::Update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		drawLines = true;

	}
}

void LightBox::Draw(RenderWindow * renderer)
{
	renderer->draw(light);
	if (drawLines == true)
	{
		DrawLines(renderer);
	
	}
}


void LightBox::DrawLines(RenderWindow * renderer)
{
	sf::Vertex line[2];
	line[0].color = sf::Color::Green;
	line[1].color = sf::Color::Green;
	blocks = game->GetBoxArray();
	float rot = 0;
	newPos = Vector2f(pos.x + 5, pos.y + 5);
	ray = new Raycast(newPos, 0.0f);
	bool foundIntersection = false;
	int w = game->getWidth();
	int h = game->getHeigth();

	RectangleShape rect;

	Vector2f finalVec;
	Vector2f tempvec;

	line[0].position = newPos;
	rect.setSize(Vector2f(10, 10));
	rect.setFillColor(Color::Magenta);

	for (int i = 0; i < blocks.size(); i++)
	{
		tempvec = ray->pos - blocks[i]->tl;

		L1Start = newPos;
		L1End = newPos + (tempvec * 1.05f);//(float)(w));
		L2Start = Vector2f(0, 0);
		L2End = Vector2f(w, 0);
		rect.setPosition(L1Start);
		renderer->draw(rect);
		rect.setPosition(L1End);
		renderer->draw(rect);
		rect.setPosition(L2Start);
		renderer->draw(rect);
		rect.setPosition(L2End);
		renderer->draw(rect);

		Vector2f intersectionpoint;

		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(0,h), Vector2f(0, 0), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}

		line[1].position = finalVec;

		renderer->draw(line, 2, sf::Lines);

		//

		tempvec = -ray->pos - blocks[i]->tr;

		L1End = newPos + (tempvec * 1.05f);//(float)(w));
		L2Start = Vector2f(w, 0);
		L2End = Vector2f(w, h - 10);
		rect.setPosition(L1Start);
		renderer->draw(rect);
		rect.setPosition(L1End);
		renderer->draw(rect);
		rect.setPosition(L2Start);
		renderer->draw(rect);
		rect.setPosition(L2End);
		renderer->draw(rect);


		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}


		line[1].position = finalVec;

		renderer->draw(line, 2, sf::Lines);

		//

		tempvec = ray->pos - blocks[i]->bl;


		L1End = newPos + (tempvec * 1.05f);//(float)(w));
		L2Start = Vector2f(w, h - 10);
		L2End = Vector2f(0, h -10);
		rect.setPosition(L1Start);
		renderer->draw(rect);
		rect.setPosition(L1End);
		renderer->draw(rect);
		rect.setPosition(L2Start);
		renderer->draw(rect);
		rect.setPosition(L2End);
		renderer->draw(rect);



		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}


		line[1].position = finalVec;

		renderer->draw(line, 2, sf::Lines);

		//

		tempvec = ray->pos - blocks[i]->br;



		L1End = newPos + (tempvec * 1.05f);//(float)(w));
		L2Start = Vector2f(0, h - 10);
		L2End = Vector2f(0, 0);
		rect.setPosition(L1Start);
		renderer->draw(rect);
		rect.setPosition(L1End);
		renderer->draw(rect);
		rect.setPosition(L2Start);
		renderer->draw(rect);
		rect.setPosition(L2End);
		renderer->draw(rect);



		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}
		if (ray->LineSegmentIntersectionPoint(newPos, newPos + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), intersectionpoint) == true)
		{
			finalVec = intersectionpoint;
			foundIntersection = true;
		}


		line[1].position = finalVec;

		renderer->draw(line, 2, sf::Lines);
	}

}



