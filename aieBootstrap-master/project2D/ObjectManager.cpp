#include "ObjectManager.h"
#include "GameObject.h"


ObjectManager::ObjectManager()
{
}




ObjectManager::~ObjectManager()
{
}

void ObjectManager::addGameObject(GameObject * go)
{
	goArray.push_back(go);
}

std::vector<GameObject*> ObjectManager::getGOArray()
{
	return goArray;
}

void ObjectManager::clearByString(std::string tag)
{

	std::vector<GameObject*>::iterator iter = goArray.begin();



	for ( ; iter != goArray.end(); )
	{
		GameObject* ptr = *iter;

		if (ptr->GetTag() == tag)
		{
			//gives back a valid iterator
			iter = goArray.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

