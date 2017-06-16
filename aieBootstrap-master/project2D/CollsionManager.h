#pragma once
#include <vector>
class GameObject;

class CollsionManager
{
public:
	CollsionManager();
	~CollsionManager();

	void UpdateCollision(std::vector<GameObject*>& GOArray);
private:
	
	bool CheckCircleCollision(GameObject& object1, GameObject& object2);

};

