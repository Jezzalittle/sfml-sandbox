#include "Blocks.h"


Blocks::Blocks(Vector2f a_tl, Vector2f a_tr, Vector2f a_bl, Vector2f a_br)
{
	tl = a_tl;
	tr = a_tr;
	bl = a_bl;
	br = a_br;
	Start();
}

void Blocks::Start()
{
	box.setPointCount(4);
	box.setPoint(0, tl);
	box.setPoint(1, tr);
	box.setPoint(2, br);
	box.setPoint(3, bl);

	box.setFillColor(sf::Color::Green);

	vertexArr.push_back(tl);
	vertexArr.push_back(tr);
	vertexArr.push_back(bl);
	vertexArr.push_back(br);
}

void Blocks::Update(float deltaTime)
{

}

void Blocks::Draw(RenderWindow* renderer)
{
	renderer->draw(box);
}

Blocks::~Blocks()
{
}
