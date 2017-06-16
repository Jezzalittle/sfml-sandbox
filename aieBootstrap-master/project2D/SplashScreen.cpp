#include "SplashScreen.h"
#include "GameManager.h"


SplashScreen::SplashScreen()
{
	nameOfScene = "SplashScreenScene";

	GameManager::instance().sm->CreateScene(this);
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::Update(float deltaTime)
{
}

void SplashScreen::Draw(aie::Renderer2D * r2d)
{
}

void SplashScreen::StartUp()
{
	std::cout << nameOfScene << std::endl;
	GameManager::instance().sm->ChangeScene("GameScene");
}

void SplashScreen::ShutDown()
{
}
