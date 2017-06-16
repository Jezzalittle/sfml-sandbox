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

