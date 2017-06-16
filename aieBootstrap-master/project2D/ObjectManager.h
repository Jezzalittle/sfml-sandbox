#pragma once
#include <vector>
class GameObject;
class Shape;


class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void addGameObject(GameObject* go);
	std::vector<GameObject*> getGOArray();

	
private:
	std::vector <GameObject* > goArray;
	

};

