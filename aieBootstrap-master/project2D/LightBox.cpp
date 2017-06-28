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
				ray = new Raycast(transform.GetPosition(), (shapeArr[i]->getVertex()[j] - perpVector * 550) + (tempvec * (float)(500)));
				rayArr.insert(rayArr.begin(), ray);
				ray = new Raycast(transform.GetPosition(), (shapeArr[i]->getVertex()[j] + perpVector *550) + (tempvec * (float)(500)));
				rayArr.insert(rayArr.begin(),ray);
			}
		}
		return rayArr;
}

void LightBox::sortArrayByRot(std::vector<Raycast*>& rayArr)
{


	Raycast* temp;

	for (int i = 1; i< rayArr.size(); ++i)
	{
		for (int j = 0; j<(rayArr.size() - i); ++j)
			if (rayArr[j]->GetDegree() > rayArr[j + 1]->GetDegree())
			{
				temp = rayArr[j];
				rayArr[j] = rayArr[j + 1];
				rayArr[j + 1] = temp;
			}

	}




//	return std::vector<Vector2*>();
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

void LightBox::CleanUpArray(std::vector<Raycast*>& a_rayArr)
{
	Vector2 vecBetween;
	float distance;
	std::vector<Raycast*>::iterator iter = a_rayArr.begin();

	for (; iter != a_rayArr.end();)
	{
		if (iter != a_rayArr.end() - 1)
		{
			vecBetween = (*iter)->endingPos - (*(iter + 1))->endingPos;
			distance = vecBetween.Magnitude();

			if (distance < 5)
			{
				iter = a_rayArr.erase(iter);
				continue;
			}
		}

		iter++;
	}

}



LightBox::~LightBox()
{
}
