#include "Shape.h"



Shape::Shape() : GameObject()
{
}

Shape::Shape(Vector2 tl, Vector2 tr, Vector2 br, Vector2 bl) : GameObject()
{
	addVetex(tl);
	addVetex(tr);
	addVetex(br);
	addVetex(bl);

	tag = "Shape";
	middle.x = (tl.x + tr.x) / 2;
	middle.y = (tl.y + bl.y) / 2;
}

void Shape::addVetex(Vector2 v2)
{
	vertexArr.push_back(v2);
}


std::vector<Vector2> Shape::getVertex()
{
	return vertexArr;
}

void Shape::Draw(aie::Renderer2D * renderer)
{
	for (size_t i = 0; i < vertexArr.size(); i++)
	{
		if (i == vertexArr.size() - 1)
		{
			renderer->drawLine(vertexArr[i].x, vertexArr[i].y, vertexArr[0].x, vertexArr[0].y, 1.0f);
		}
		else
		{
			renderer->drawLine(vertexArr[i].x, vertexArr[i].y, vertexArr[i + 1].x, vertexArr[i + 1].y, 1.0f);
		}
	}
}

void Shape::Update(float deltaTime)
{
}

Vector2 Shape::GetMiddle()
{
	return middle;
}

Shape::~Shape()
{
}
