#include "GameManager.h"



GameManager::GameManager()
{
	tm = new TextureManager();
	sm = new SceneManager();
	om = new ObjectManager();
	cm = new CollsionManager();
	DrawRays = true;
}


GameManager::~GameManager()
{

}



TextureManager * GameManager::getTM()
{
	return tm;
}

Vector4 GameManager::GetRendererColor()
{
	return color;
}

void GameManager::SetRendererColor(float x, float y, float z, float w)
{
	color.x = x;
	color.y = y; 
	color.z = z;
	color.w = w;
}
