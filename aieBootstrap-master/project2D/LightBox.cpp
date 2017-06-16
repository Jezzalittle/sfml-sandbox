#include "LightBox.h"
#include "GameManager.h"
#include "Shape.h"
#include "Raycast.h"


LightBox::LightBox() : GameObject()
{
	aie::Input* input = aie::Input::getInstance();
}
LightBox::LightBox(Vector2 a_pos) : GameObject()
{
	aie::Input* input = aie::Input::getInstance();
	transform.SetPosition(a_pos);
	tag = "LightBox";

}



void LightBox::Draw(aie::Renderer2D * renderer)
{
	renderer->drawBox(transform.GetPosition().x, transform.GetPosition().y, 5, 5);
}

void LightBox::Update(float deltaTime)
{


}

std::vector<Raycast*> LightBox::MakeRays(std::vector<Shape*> shapeArr)
{
	std::vector<Raycast*> rayArr;


	
		for (size_t i = 0; i < shapeArr.size(); i++)
		{
			for (size_t j = 0; j < shapeArr[i]->getVertex().size(); j++)
			{

				Vector2 tempvec = shapeArr[i]->getVertex()[j] - transform.GetPosition();



				Raycast* ray = new Raycast(transform.GetPosition(), shapeArr[i]->getVertex()[j] + (tempvec * (float)(500)));
				rayArr.push_back(ray);
				ray = new Raycast(transform.GetPosition(), (shapeArr[i]->getVertex()[j] - Vector2(1, 1)) + (tempvec * (float)(500)));
				rayArr.push_back(ray);
				ray = new Raycast(transform.GetPosition(), (shapeArr[i]->getVertex()[j] + Vector2(1,1)) + (tempvec * (float)(500)));
				rayArr.push_back(ray);
			}
		}
		return rayArr;
}


LightBox::~LightBox()
{
}
