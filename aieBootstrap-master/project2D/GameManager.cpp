#include "GameManager.h"



GameManager::GameManager()
{
	tm = new TextureManager();
	sm = new SceneManager();
	om = new ObjectManager();
	cm = new CollsionManager();
}


GameManager::~GameManager()
{

}



TextureManager * GameManager::getTM()
{
	return tm;
}
