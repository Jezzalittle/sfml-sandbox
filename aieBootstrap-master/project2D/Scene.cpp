#include "Scene.h"
#include "GameManager.h"



Scene::Scene()
{
	
}


Scene::~Scene()
{
}

std::string Scene::GetSceneName()
{
	return nameOfScene;
}

void Scene::Update(float deltaTime)
{

}

void Scene::Draw(aie::Renderer2D* r2d)
{
}

void Scene::StartUp()
{

}

void Scene::ShutDown()
{
}
