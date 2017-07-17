#pragma once
#include "TextureManager.h"
#include "Vector2.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollsionManager.h"
#include "Vector4.h"

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

	bool DrawRays;


	Vector4 GetRendererColor();
	void SetRendererColor(float x, float y, float z, float w);

	
	

private:
	GameManager();
	Vector4 color;

};

