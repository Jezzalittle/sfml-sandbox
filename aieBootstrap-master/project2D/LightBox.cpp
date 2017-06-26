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
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT))
	{
		transform.SetPosition(Vector2(input->getMouseX(), input->getMouseY()));
	}

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

				Vector2 perpVector(tempvec.y, -tempvec.x);
				perpVector = perpVector.Normalised();

				rayArr.insert(rayArr.begin(), ray);
				ray = new Raycast(transform.GetPosition(), (shapeArr[i]->getVertex()[j] - perpVector * 1000.0f) + (tempvec * (float)(500)));
				rayArr.insert(rayArr.begin(), ray);
				ray = new Raycast(transform.GetPosition(), (shapeArr[i]->getVertex()[j] + perpVector * 1000.0f) + (tempvec * (float)(500)));
				rayArr.insert(rayArr.begin(),ray);
			}
		}
		return rayArr;
}

std::vector<Vector2*> LightBox::sortArrayByRot(std::vector<Raycast*> rayArr)
{
	return std::vector<Vector2*>();
}

std::vector<Shape*> LightBox::sortShapes(std::vector<Shape*> shapesArr)
{
	std::vector<Shape*> resortedArr;

	int n = shapesArr.size();

	resortedArr = shapesArr;
	
	Shape* temp;

	for (int i = 1; i<n; ++i)
	{
		for (int j = 0; j < (n - i); ++j)
		{
			Vector2 VecBetweenIndex = resortedArr[j]->GetMiddle() - GetPosition();
			Vector2 VecBetweenIndex2 = resortedArr[j + 1]->GetMiddle() - GetPosition();

			if (VecBetweenIndex.Magnitude() < VecBetweenIndex2.Magnitude())
			{
				temp = resortedArr[j];
				resortedArr[j] = resortedArr[j + 1];
				resortedArr[j + 1] = temp;
			}
		}
	}

	return shapesArr;

}




LightBox::~LightBox()
{
}
