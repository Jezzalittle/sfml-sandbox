#include "GameScene.h"
#include "GameObject.h"
#include "GameManager.h"
#include "Shape.h"
#include "LightBox.h"
#include "Raycast.h"


GameScene::GameScene()
{
	nameOfScene = "GameScene";
	GameManager::instance().sm->CreateScene(this);
}

void GameScene::StartUp()
{
	std::cout << nameOfScene << std::endl;
	aie::Input* input = aie::Input::getInstance();
	firstPress = true;
	UpdateShapes = false;



}

void GameScene::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	GOarray = GameManager::instance().om->getGOArray();
	for (size_t i = 0; i < GOarray.size(); i++)
	{
		GOarray[i]->Update(deltaTime);
	}

	if (input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT) && firstPress ==  true)
	{
		if (UpdateShapes == true)
		{
			ShapeArr = lightBox->sortShapes(ShapeArr);
			UpdateShapes = false;
		}

		tl = Vector2((float)input->getMouseX(), (float)input->getMouseY());
		firstPress = false;
	}
	else if (input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT) && firstPress == false)
	{
		br = Vector2((float)input->getMouseX(), (float)input->getMouseY());
		tr = Vector2(br.x, tl.y);
		bl = Vector2(tl.x, br.y);

		Shape* shape = new Shape(tl,tr,br,bl);
		ShapeArr.push_back(shape);
		firstPress = true;
	}




	if (input->wasKeyPressed(aie::INPUT_KEY_L))
	{
		lightBox = new LightBox(Vector2(input->getMouseX(), input->getMouseY()));
	}


	if (input->wasKeyPressed(aie::INPUT_KEY_P))
	{

		clearRayArr();
		UpdateShapes = true;
		rayArr = lightBox->MakeRays(ShapeArr);

		Shape* shape = new Shape(Vector2(0, 0), Vector2(GameManager::instance().screenRes.x, 0), Vector2(GameManager::instance().screenRes.x, GameManager::instance().screenRes.y), Vector2(0, GameManager::instance().screenRes.y));
		ShapeArr.insert(ShapeArr.begin(),shape);

		if(lightBox != nullptr)
		{
			for (size_t i = 0; i < rayArr.size(); i++)
			{
				rayArr[i]->CheckForRaycollision(ShapeArr);
			}
		}
	}


	GameManager::instance().cm->UpdateCollision(GOarray);
}

void GameScene::Draw(aie::Renderer2D* renderer)
{
	GOarray = GameManager::instance().om->getGOArray();
	for (size_t i = 0; i < GOarray.size(); i++)
	{
		if (GOarray[i] != nullptr)
		{
		GOarray[i]->Draw(renderer);
		}
	}
}

std::vector<Shape*> GameScene::GetShapeArr()
{
	return ShapeArr;
}


GameScene::~GameScene()
{
}

void GameScene::clearRayArr()
{
	rayArr.clear();
	GameManager::instance().om->clearByString("ray");
}
