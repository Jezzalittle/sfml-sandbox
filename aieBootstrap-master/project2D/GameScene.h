#pragma once
#include "Application2D.h"
#include "Scene.h"
#include <vector>
#include "Vector2.h"

class Raycast;
class LightBox;
class Shape;
class GameObject;

class GameScene : public Scene
{
public:
	GameScene();

	void StartUp();
	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);
	std::vector <Shape*> GetShapeArr();

	~GameScene();
private:

	void clearRayArr();

	std::vector <GameObject*> GOarray; 
	std::vector <Shape*> ShapeArr;
	aie::Input* input;
	bool firstPress;
	bool UpdateShapes;

	float rayRefreshTimer;
	LightBox* lightBox;
	std::vector<Raycast*> rayArr;


	Vector2 tl;
	Vector2 tr;
	Vector2 bl;
	Vector2 br;
	Vector2 mid;

};

// make the shapes bertexes bigger