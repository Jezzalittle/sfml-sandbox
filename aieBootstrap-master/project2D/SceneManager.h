#pragma once
#include <iostream>
#include <vector>
class Scene;
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	
	void CreateScene (Scene* scene);

	void ChangeScene(std::string SceneName);

	Scene* GetCurrnetScene();
	
	int GetSceneCount;




private:
	Scene* FindSceneByName(std::string);
	Scene* currrentScene;
	std::vector < Scene* > sceneArr;
	int Count;
};

