#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Scene.h"
#include "GameManager.h"
#include "Vector2.h"
#include "SplashScreen.h"
#include "GameScene.h"


Application2D::Application2D() {
}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	


	GameManager& gm = GameManager::instance();
	gm.screenRes = (Vector2(getWindowWidth(), getWindowHeight()));
	renderer = new aie::Renderer2D();
	splashScreenScene = new SplashScreen();
	gameScene = new GameScene();

	gm.sm->GetCurrnetScene()->StartUp();

	return true;
}

aie::Renderer2D * Application2D::getRenderer()
{
	return renderer;
}

void Application2D::update(float deltaTime)
{
	currentScene = GameManager::instance().sm->GetCurrnetScene();
	aie::Input* input = aie::Input::getInstance();
	deltaTime += deltaTime;

	// input example


	currentScene->Update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

}

float Application2D::getDeltaTime()
{
	return deltaTime;
}


void Application2D::shutdown() {
	
	delete renderer;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	renderer->begin();

	currentScene->Draw(renderer);

	// done drawing sprites
	renderer->end();
}


