#include "CollsionManager.h"
#include "GameObject.h"


CollsionManager::CollsionManager()
{
}


CollsionManager::~CollsionManager()
{
}

void CollsionManager::UpdateCollision(std::vector<GameObject*>& GOArray)
{

	for (size_t i = 0; i < GOArray.size(); i++)
	{
		for (size_t j = i + 1; j < GOArray.size(); j++)
		{
			//Push them Apart


			if (CheckCircleCollision(*GOArray[i], *GOArray[j]))
			{
				GOArray[i]->OnCollision(*GOArray[j]);
				GOArray[j]->OnCollision(*GOArray[i]);
			}
		}
	}

}

bool CollsionManager::CheckCircleCollision(GameObject & object1, GameObject & object2)
{

	Vector2 vecBetween = object2.GetPosition() - object1.GetPosition();

	if (vecBetween.Magnitude() < object2.GetRadius() + object1.GetRadius())
	{
		return true;
	}
	return false;

}
