#include "Raycast.h"


Raycast::Raycast(Vector2 p1, Vector2 p2) : GameObject()
{
	beginingPos = p1;
	endingPos = p2;
}

Raycast::Raycast() : GameObject()
{
	beginingPos = Vector2();
	endingPos = Vector2();
}

void Raycast::Draw(aie::Renderer2D * renderer)
{
	renderer->drawLine(beginingPos.x, beginingPos.y, endingPos.x, endingPos.y);
}

Vector2 Raycast::LineIntersectionPoint(Raycast* ray2)
{
	// Get A,B,C of first line - points : ps1 to pe1
	float A1 = endingPos.y - beginingPos.y;
	float B1 = beginingPos.x - endingPos.x;
	float C1 = A1*beginingPos.x + B1*beginingPos.y;

	// Get A,B,C of second line - points : ps2 to pe2
	float A2 = ray2->endingPos.y - ray2->beginingPos.y;
	float B2 = ray2->beginingPos.x - ray2->endingPos.x;
	float C2 = A2* ray2->beginingPos.x + B2* ray2->beginingPos.y;

	// Get delta and check if the lines are parallel
	float delta = A1*B2 - A2*B1;
	
	if (delta == 0)
	{
		return Vector2(-1, -1);
	}

	std::cout << " " << A2 << std::endl;
	// now return the Vector2 intersection point
	return Vector2((B2*C1 - B1*C2) / delta, (A1*C2 - A2*C1) / delta);
}

bool Raycast::LineSegmentIntersectionPoint(Vector2 pos1, Vector2 pos2, Vector2& intersectionPoint)
{

	// Get A,B,C of first line - points : ps1 to pe1
	float A1 = endingPos.y - beginingPos.y;
	float B1 = beginingPos.x - endingPos.x;
	float C1 = A1*beginingPos.x + B1*beginingPos.y;

	// Get A,B,C of second line - points : ps2 to pe2
	float A2 = pos2.y - pos1.y;
	float B2 = pos2.x - pos1.x;
	float C2 = A2* pos1.x + B2* pos2.y;


	// Get delta and check if the lines are parallel
	float delta = A1*B2 - A2*B1;
	if (delta == 0)
		return false;

	std::cout << " " << A2 << std::endl;


	// now return the Vector2 intersection point
	intersectionPoint = Vector2((B2*C1 - B1*C2) / delta, (A1*C2 - A2*C1) / delta);

	//CHECK SECOND LINE
	Vector2 line2 = pos2 - pos1;
	Vector2 centerOfLine2 = pos1 + (line2 / 2.0f);

	float line2Magnitude = sqrt(line2.x*line2.x + line2.y*line2.y);

	Vector2 vecBetweenCenterAndIntersection = centerOfLine2 - intersectionPoint;

	if (sqrt(vecBetweenCenterAndIntersection.x*vecBetweenCenterAndIntersection.x + vecBetweenCenterAndIntersection.y*vecBetweenCenterAndIntersection.y) > line2Magnitude / 2.0f)
	{
		return false;
	}

	//CHECK FIRST LINE
	Vector2 line1 = endingPos - beginingPos;
	Vector2 centerOfLine1 = beginingPos + (line1 / 2.0f);

	float line1Magnitude = sqrt(line1.x*line1.x + line1.y*line1.y);

	vecBetweenCenterAndIntersection = centerOfLine1 - intersectionPoint;

	if (sqrt(vecBetweenCenterAndIntersection.x*vecBetweenCenterAndIntersection.x + vecBetweenCenterAndIntersection.y*vecBetweenCenterAndIntersection.y) > line1Magnitude / 2.0f)
	{
		return false;
	}




	return true;
}

void Raycast::CheckForRaycollision(std::vector<Shape*> shapeArr)
{

	Vector2 intersect;

	for (size_t i = 0; i < shapeArr.size(); i++)
	{

			//this sucks debug slowly

			//checks over each vertex
			for (int j = 0; j < shapeArr[i]->getVertex().size(); j++)
			{
				//each wall
				// If at end loop back
				//ray from light source to vertex, against edge of box
				if (LineSegmentIntersectionPoint(shapeArr[i]->getVertex()[0], shapeArr[i]->getVertex()[1], intersect))
				{
					endingPos = intersect;
				}
				else if (LineSegmentIntersectionPoint(shapeArr[i]->getVertex()[1], shapeArr[i]->getVertex()[2], intersect))
				{
					endingPos = intersect;
				}
				else if (LineSegmentIntersectionPoint(shapeArr[i]->getVertex()[2], shapeArr[i]->getVertex()[3], intersect))
				{
					endingPos = intersect;
				}
				else if (LineSegmentIntersectionPoint(shapeArr[i]->getVertex()[3], shapeArr[i]->getVertex()[0], intersect))
				{
					endingPos = intersect;
				}

		}

		


	}
}



