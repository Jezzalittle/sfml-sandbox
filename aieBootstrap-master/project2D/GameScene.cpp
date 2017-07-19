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
	lightBox = nullptr;
	colorArr[3] = 255;
	colorArr[0] = 255;
	GameManager::instance().DrawRays = false;
}

void GameScene::Update(float deltaTime)
{
	rayRefreshTimer += deltaTime;

	aie::Input* input = aie::Input::getInstance();
	GOarray = GameManager::instance().om->getGOArray();
	for (size_t i = 0; i < GOarray.size(); i++)
	{
		GOarray[i]->Update(deltaTime);
	}
	

	ImGui::Begin("Command Menu");
	ImGui::Text("Use Right Click to Create Objects");
	ImGui::Text("Press L To Create A Light");
	ImGui::Text("Hold Left Shift to Move The Light");
	ImGui::Checkbox("Draw Rays", &GameManager::instance().DrawRays);
	ImGui::ColorEdit4("Color", colorArr);


	ImGui::End();

	GameManager::instance().SetRendererColor(colorArr[0], colorArr[1], colorArr[2], colorArr[3]);

	if (input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_RIGHT))
	{
		vertsArr.push_back((Vector2(input->getMouseX(), input->getMouseY())));
	}


	if (input->wasKeyPressed(aie::INPUT_KEY_ENTER))
	{
		ShapeArr.push_back(new Shape(vertsArr));
		vertsArr.clear();
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_L))
	{
		
		lightBox = new LightBox(Vector2(input->getMouseX(), input->getMouseY()));
		Shape* shape = new Shape(Vector2(0, 0), Vector2(GameManager::instance().screenRes.x, 0), Vector2(GameManager::instance().screenRes.x, GameManager::instance().screenRes.y), Vector2(0, GameManager::instance().screenRes.y));
		ShapeArr.insert(ShapeArr.begin(), shape);
	}



	if (lightBox != nullptr)
	{
		clearLightTrianglesArr();
		clearRayArr();
		UpdateShapes = true;
		rayArr = lightBox->MakeRays(ShapeArr);
		lightBox->sortArrayByRot(rayArr);

		for (size_t i = 0; i < rayArr.size(); i++)
		{
			rayArr[i]->CheckForRaycollision(ShapeArr);
		}

		lightBox->CleanUpArray(rayArr);
		lightBox->MakeLightTriangles(rayArr);
	}




	GameManager::instance().cm->UpdateCollision(GOarray);
}

void GameScene::Draw(aie::Renderer2D* renderer)
{
	GOarray = GameManager::instance().om->getGOArray();

	//renderer->drawTriangle(nullptr, 10,10, 500,500, 10,350);



	for (size_t i = 0; i < GOarray.size(); i++)
	{
		if (GOarray[i] != nullptr)
		{
			GOarray[i]->Draw(renderer);
		}
	}
	for (size_t i = 0; i < rayArr.size(); i++)
	{
		if (rayArr[i] != nullptr)
		{
			rayArr[i]->Draw(renderer);
		}
	}

}

std::vector<Shape*> GameScene::GetShapeArr()
{
	return ShapeArr;
}

void GameScene::clearRayArr()
{
	rayArr.clear();
	GameManager::instance().om->clearByString("ray");
}

void GameScene::clearLightTrianglesArr()
{
	GameManager::instance().om->clearByString("triangle");
}

GameScene::~GameScene()
{
}

