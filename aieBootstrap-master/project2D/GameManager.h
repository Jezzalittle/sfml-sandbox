#pragma once
#include "TextureManager.h"
#include "Vector2.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollsionManager.h"

class GameManager
{
public:

	~GameManager();

	static GameManager& instance()
	{	
		static GameManager* instance = new GameManager();
		return *instance;
	}
	


	CollsionManager* cm;
	TextureManager* tm;
	SceneManager* sm;
	ObjectManager* om;

	TextureManager* getTM();

	Vector2 screenRes;

private:
	GameManager();


};

