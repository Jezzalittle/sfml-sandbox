#include "SceneManager.h"
#include "Scene.h"


SceneManager::SceneManager()
{
	Count = 0;
}


SceneManager::~SceneManager()
{
}

void SceneManager::CreateScene(Scene* scene)
{
	Count++;
	sceneArr.push_back(scene);
	if (sceneArr.size() == 1)
	{
		currrentScene = scene;
	}
}

void SceneManager::ChangeScene(std::string SceneName)
{
	currrentScene->ShutDown();
	currrentScene = FindSceneByName(SceneName);
	currrentScene->StartUp();
}

Scene * SceneManager::GetCurrnetScene()
{
	return currrentScene;
}

Scene* SceneManager::FindSceneByName(std::string s)
{
	for (size_t i = 0; i < sceneArr.size(); i++)
	{
		if (sceneArr[i]->GetSceneName() == s)
		{
			return sceneArr[i];
		}
	}
}

