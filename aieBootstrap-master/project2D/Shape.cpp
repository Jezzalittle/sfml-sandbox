#include "Shape.h"
#include "GameManager.h"


Shape::Shape() : GameObject()
{
}

Shape::Shape(Vector2 tl, Vector2 tr, Vector2 br, Vector2 bl) : GameObject()
{
	addVetex(tl);
	addVetex(tr);
	addVetex(br);
	addVetex(bl);

	tag = "rectangle";
	middle.x = (tl.x + tr.x) / 2;
	middle.y = (tl.y + bl.y) / 2;
}

Shape::Shape(aie::Texture* a_texture, Vector2 xy1, Vector2 xy2, Vector2 xy3) : GameObject()
{
	addVetex(xy1);
	addVetex(xy2);
	addVetex(xy3);
	texture = a_texture;
	
	//**********************
	texture = GameManager::instance().tm->FindByFileName("tankRed.png");

	tag = "triangle";
	
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
	if (vertexArr.size() == 4)
	{
		for (size_t i = 0; i < vertexArr.size(); i++)
		{
			if (i == vertexArr.size() - 1)
			{
				renderer->drawLine(vertexArr[i].x, vertexArr[i].y, vertexArr[0].x, vertexArr[0].y, 3.0f, -1);
			}
			else
			{
				renderer->drawLine(vertexArr[i].x, vertexArr[i].y, vertexArr[i + 1].x, vertexArr[i + 1].y, 3.0f, -1);
			}
		}
	}
	else if (vertexArr.size() == 3)
	{
		
		renderer->setRenderColour(GameManager::instance().GetRendererColor().x, GameManager::instance().GetRendererColor().y, GameManager::instance().GetRendererColor().z, GameManager::instance().GetRendererColor().w);
		renderer->drawTriangle(nullptr, vertexArr[0].x, vertexArr[0].y, vertexArr[1].x, vertexArr[1].y, vertexArr[2].x, vertexArr[2].y);
		renderer->setRenderColour(1, 1, 1);

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
