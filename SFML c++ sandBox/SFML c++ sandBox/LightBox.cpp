#include "LightBox.h"
#include "Blocks.h"
#include "Game.h"
#include <vector>
#include <cmath>

#include <iostream>

float magnitude(Vector2f a)
{
	return sqrt(a.x*a.x + a.y*a.y);
}

Vector2f normalise(Vector2f a)
{
	float mag = magnitude(a);
	if (mag == 0)
		return a;

	return Vector2f(a.x / mag, a.y / mag);
}


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

	//CHECK SECOND LINE
	Vector2f line2 = le2 - ls2;
	Vector2f centerOfLine2 = ls2 + (line2 / 2.0f);

	float line2Magnitude = sqrt(line2.x*line2.x + line2.y*line2.y);

	Vector2f vecBetweenCenterAndIntersection = centerOfLine2 - intersectionPoint;

	if (sqrt(vecBetweenCenterAndIntersection.x*vecBetweenCenterAndIntersection.x + vecBetweenCenterAndIntersection.y*vecBetweenCenterAndIntersection.y) > line2Magnitude / 2.0f)
	{
		return false;
	}

	//CHECK FIRST LINE
	Vector2f line1 = le1 - ls1;
	Vector2f centerOfLine1 = ls1 + (line1 / 2.0f);

	float line1Magnitude = sqrt(line1.x*line1.x + line1.y*line1.y);

	vecBetweenCenterAndIntersection = centerOfLine1 - intersectionPoint;

	if (sqrt(vecBetweenCenterAndIntersection.x*vecBetweenCenterAndIntersection.x + vecBetweenCenterAndIntersection.y*vecBetweenCenterAndIntersection.y) > line1Magnitude / 2.0f)
	{
		return false;
	}




	return true;
}

//Vector2f Raycast::CheckRayCol(Vector2f lightBox, Vector2f vetexChecking, Vector2f edgeVetex1, Vector2f edgeVetex2, Raycast* ray)
//{
//	Vector2f result;
//	ray->LineSegmentIntersectionPoint(lightBox, vetexChecking, edgeVetex1, edgeVetex2, result);
//	return result;
//}
//
//std::vector<Vector2f*> Raycast::getAllColForABox(Vector2f lightBox, Vector2f tl, Vector2f tr, Vector2f bl, Vector2f br, Raycast*ray)
//{
//
//	std::vector<Vector2f> result;
//	Vector2f temp;
//	
//	if (ray->LineSegmentIntersectionPoint(lightBox, tl, tl, tr, temp))
//	{
//		result.push_back(temp);
//		std::cout << "top edge hit" << std::endl;
//	}
//	if (ray->LineSegmentIntersectionPoint(lightBox, tl, tl, tr, temp))
//	{
//		result.push_back(temp);
//		std::cout << "top edge hit" << std::endl;
//	}
//	if (ray->LineSegmentIntersectionPoint(lightBox, tl, tl, tr, temp))
//	{
//		result.push_back(temp);
//		std::cout << "top edge hit" << std::endl;
//	}
//	if (ray->LineSegmentIntersectionPoint(lightBox, tl, tl, tr, temp))
//	{
//		result.push_back(temp);
//		std::cout << "top edge hit" << std::endl;
//	}
//
//	result.push_back(CheckRayCol(lightBox, tl, tl, tr, ray));
//	result.push_back(CheckRayCol(lightBox, tl, tl, tr, ray));
//	result.push_back(CheckRayCol(lightBox, tl, tl, tr, ray));
//	result.push_back(CheckRayCol(lightBox, tl, tl, tr, ray));
//
//
//}
//
//std::vector<std::vector<Vector2f*>> Raycast::getAllCol(Vector2f lightBox, std::vector<Blocks*> boxArrays)
//{
//	return std::vector<std::vector<Vector2f*>>();
//}




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
	LightBoxPos = Vector2f(pos.x + 5, pos.y + 5);
	ray = new Raycast(LightBoxPos, 0.0f);
	bool foundIntersection = false;
	int w = game->getWidth();
	int h = game->getHeigth();

	RectangleShape rect;

	Vector2f finalVec;
	Vector2f tempvec;

	Vector2f intersect;

	Vector2f temp;



	std::vector < Vector2f > lightShapePoints;
	std::vector < Vector2f> badList;
	line[0].position = LightBoxPos;
	rect.setSize(Vector2f(10, 10));
	rect.setFillColor(Color::Magenta);

	Vector2f tempVecBetween;

	for (size_t i = 0; i < blocks.size(); i++)
	{
		int tempLength = blocks[i]->vertexArr.size();
		for (size_t j = 0; j < tempLength; j++)
		{

			Vector2f vertex = blocks[i]->vertexArr[j];

			//get perpindicular vectors
			Vector2f leftPerpVertex(-vertex.y, vertex.x);
			Vector2f rightPerpVertex(vertex.y, -vertex.x);

			//normalise vectors
			leftPerpVertex  = normalise(leftPerpVertex) * 20.0f;
			rightPerpVertex = normalise(rightPerpVertex) * 20.0f;

			//add left and right perp to the vector
			blocks[i]->vertexArr.push_back(vertex + leftPerpVertex);
			blocks[i]->vertexArr.push_back(vertex + rightPerpVertex);

			//temp = (Vector2f(-blocks[i]->vertexArr[j].y, blocks[i]->vertexArr[j].x));
			//tempLength = sqrt((temp.x * temp.x) + (temp.y + temp.y));
			//temp = temp + Vector2f(temp.x / tempLength, temp.y / tempLength);
			//lightShapePoints.push_back(temp);
			//temp = (Vector2f(blocks[i]->vertexArr[j].y, -blocks[i]->vertexArr[j].x));
			//tempLength = sqrt((temp.x * temp.x) + (temp.y + temp.y));
			//temp = temp + Vector2f(temp.x / tempLength, temp.y / tempLength);
			//lightShapePoints.push_back(temp); 

			//temp = Vector2f(blocks[i]->vertexArr[j].x + 10, blocks[i]->vertexArr[j].y + 10);
			//tempVecBetween = temp - ray->pos;
			//tempVecBetween = Vector2f(temp.x * (w * 2), temp.y * (w * 2));
			//blocks[i]->vertexArr.push_back(tempVecBetween);
			//temp = Vector2f(blocks[i]->vertexArr[j].x - 10, blocks[i]->vertexArr[j].y - 10);
			//tempVecBetween = temp - ray->pos;
			//tempVecBetween = Vector2f(temp.x * (w * 2), temp.y * (w * 2));
			//blocks[i]->vertexArr.push_back(tempVecBetween);

			// the points arent long enough 
		}
	}

	//goes over each box

	for (int i = 0; i < blocks.size(); i++)
	{
		//this sucks debug slowly

	//	for (int k = 0; k < blocks.size(); k++)
	//	{


		//checks over each vertex
		for (int j = 0; j < blocks[i]->vertexArr.size(); j++)
		{
			//each wall



			tempvec = blocks[i]->vertexArr[j] - ray->pos;

			// If at end loop back
			//ray from light source to vertex, against edge of box
			if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->vertexArr[j], blocks[i]->vertexArr[0], blocks[i]->vertexArr[1], intersect))
			{
				lightShapePoints.push_back(intersect);
			}
			else if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->vertexArr[j], blocks[i]->vertexArr[1], blocks[i]->vertexArr[2], intersect))
			{
				lightShapePoints.push_back(intersect);
			}
			else if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->vertexArr[j], blocks[i]->vertexArr[2], blocks[i]->vertexArr[3], intersect))
			{
				lightShapePoints.push_back(intersect);
			}
			else if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->vertexArr[j], blocks[i]->vertexArr[3], blocks[i]->vertexArr[0], intersect))
			{
				lightShapePoints.push_back(intersect);
			}
			else if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->vertexArr[j] + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), temp) == true)
			{
				lightShapePoints.push_back(intersect);
			}
			else if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->vertexArr[j] + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), temp) == true)
			{
				lightShapePoints.push_back(intersect);
			}
			else if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->vertexArr[j] + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), temp) == true)
			{
				lightShapePoints.push_back(intersect);
			}
			else if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->vertexArr[j] + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), temp) == true)
			{
				lightShapePoints.push_back(intersect);
			}

		}


	}






	//}
	for (size_t k = 0; k < lightShapePoints.size(); k++)
	{
		line[1].position = lightShapePoints[k];
		renderer->draw(line, 2, sf::Lines);
	}





}













			//	//tl
			// 
			//	//looks to see if the ray to the top left of the box we are looking at to see if any if the edges are being colided wotj early

			//	std::cout << "checking ray from light to tl of box " << i << std::endl;
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->tl, blocks[i]->tl, blocks[i]->tr, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->tl, blocks[i]->tr, blocks[i]->br, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->tl, blocks[i]->br, blocks[i]->bl, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->tl, blocks[i]->bl, blocks[i]->tl, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}



			//	//tr

			//	std::cout << "checking ray from light to tr of box " << i << std::endl;
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->tr, blocks[i]->tl, blocks[i]->tr, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->tr, blocks[i]->tr, blocks[i]->br, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->tr, blocks[i]->br, blocks[i]->bl, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->tr, blocks[i]->bl, blocks[i]->tl, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//		
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//			
			//		}
			//	}

			//	//bl

			//	std::cout << "checking ray from light to bl of box " << i << std::endl;

			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->bl, blocks[i]->tl, blocks[i]->tr, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->bl, blocks[i]->tr, blocks[i]->br, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->bl, blocks[i]->br, blocks[i]->bl, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->bl, blocks[i]->bl, blocks[i]->tl, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}


			//	//br

			//	std::cout << "checking ray from light to br of box " << i << std::endl;

			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->br, blocks[i]->tl, blocks[i]->tr, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}

			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->br, blocks[i]->tr, blocks[i]->br, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->br, blocks[i]->br, blocks[i]->bl, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}
			//	if (ray->LineSegmentIntersectionPoint(LightBoxPos, blocks[i]->br, blocks[i]->bl, blocks[i]->tl, intersect))
			//	{
			//		if (intersect != blocks[i]->tl || intersect != blocks[i]->tr || intersect != blocks[i]->bl || intersect != blocks[i]->br)
			//		{
			//			lightShapePoints.push_back(intersect);
			//			std::cout << "top edge hit" << std::endl;
			//			badList.push_back(blocks[i]->tl);
			//		}
			//	}

			//}

			//	for (int l = 0; l < badList.size(); l++)
			//	{
			//		if (blocks[i]->tl != badList[l])
			//		{
			//			lightShapePoints.push_back(blocks[i]->tl);
			//		}
			//		if (blocks[i]->tr != badList[l])
			//		{
			//			lightShapePoints.push_back(blocks[i]->tr);
			//		}
			//		if (blocks[i]->bl != badList[l])
			//		{
			//			lightShapePoints.push_back(blocks[i]->bl);
			//		}
			//		if (blocks[i]->br != badList[l])
			//		{
			//			lightShapePoints.push_back(blocks[i]->br);
			//		}
			//	}

			//
			//for (size_t j = 0; j < lightShapePoints.size(); j++)
			//{
			//	if (lightShapePoints[j] == blocks[i]->tl)
			//	{
			//		tempvec = blocks[i]->tl - ray->pos;	

			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//	}
			//	if (lightShapePoints[j] == blocks[i]->tr)
			//	{
			//		tempvec = blocks[i]->tr - ray->pos;

			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//	}
			//	if (lightShapePoints[j] == blocks[i]->br)
			//	{
			//		tempvec = blocks[i]->br - ray->pos;

			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//	}
			//	if (lightShapePoints[j] == blocks[i]->bl)
			//	{
			//		tempvec = blocks[i]->bl - ray->pos;

			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//		if (ray->LineSegmentIntersectionPoint(LightBoxPos, lightShapePoints[j] + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), temp) == true)
			//		{
			//			lightShapePoints[j] = temp;
			//		}
			//	}

			//}


			//for (size_t k = 0; k < lightShapePoints.size(); k++)
			//{
			//	line[1].position = lightShapePoints[k];
			//	renderer->draw(line, 2, sf::Lines);
			//}















			//tempvec =  blocks[i]->tl - ray->pos;

			//L1Start = LightBoxPos;
			//L1End = LightBoxPos + (tempvec * 1.05f);//(float)(w));
			//L2Start = Vector2f(0, 0);
			//L2End = Vector2f(w, 0);
			//rect.setPosition(L1Start);
			//renderer->draw(rect);
			//rect.setPosition(L1End);
			//renderer->draw(rect);
			//rect.setPosition(L2Start);
			//renderer->draw(rect);
			//rect.setPosition(L2End);
			//renderer->draw(rect);

			//Vector2f intersectionpoint;

			////#######################################
			////the issue is to do with the line that is drawing from the light sourse to the point on the wall being infinity long which means that both sides hit the ball
			////eg if the line is going stright up it will hit the top wall as well as hitting the bottem wall
			//// ask ian for help with making the length of the light ray smaller
			////#######################################

			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(0,h), Vector2f(0, 0), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}

			//line[1].position = finalVec;

			//renderer->draw(line, 2, sf::Lines);

			////

			//tempvec =  blocks[i]->tr - ray->pos;

			//L1End = LightBoxPos + (tempvec * 1.05f);//(float)(w));
			//L2Start = Vector2f(w, 0);
			//L2End = Vector2f(w, h - 10);
			//rect.setPosition(L1Start);
			//renderer->draw(rect);
			//rect.setPosition(L1End);
			//renderer->draw(rect);
			//rect.setPosition(L2Start);
			//renderer->draw(rect);
			//rect.setPosition(L2End);
			//renderer->draw(rect);


			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}


			//line[1].position = finalVec;

			//renderer->draw(line, 2, sf::Lines);

			////

			//tempvec =  blocks[i]->bl - ray->pos;


			//L1End = LightBoxPos + (tempvec * 1.05f);//(float)(w));
			//L2Start = Vector2f(w, h - 10);
			//L2End = Vector2f(0, h -10);
			//rect.setPosition(L1Start);
			//renderer->draw(rect);
			//rect.setPosition(L1End);
			//renderer->draw(rect);
			//rect.setPosition(L2Start);
			//renderer->draw(rect);
			//rect.setPosition(L2End);
			//renderer->draw(rect);



			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}


			//line[1].position = finalVec;

			//renderer->draw(line, 2, sf::Lines);

			////

			//tempvec = blocks[i]->br - ray->pos;



			//L1End = LightBoxPos + (tempvec * 1.05f);//(float)(w));
			//L2Start = Vector2f(0, h - 10);
			//L2End = Vector2f(0, 0);
			//rect.setPosition(L1Start);
			//renderer->draw(rect);
			//rect.setPosition(L1End);
			//renderer->draw(rect);
			//rect.setPosition(L2Start);
			//renderer->draw(rect);
			//rect.setPosition(L2End);
			//renderer->draw(rect);



			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(0, 0), Vector2f(w, 0), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(w, 0), Vector2f(w, h), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(w, h), Vector2f(0, h), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}
			//if (ray->LineSegmentIntersectionPoint(LightBoxPos, LightBoxPos + (tempvec * (float)(w * 2)), Vector2f(0, h), Vector2f(0, 0), intersectionpoint) == true)
			//{
			//	finalVec = intersectionpoint;
			//	foundIntersection = true;
			//}


			//line[1].position = finalVec;

			//renderer->draw(line, 2, sf::Lines);

