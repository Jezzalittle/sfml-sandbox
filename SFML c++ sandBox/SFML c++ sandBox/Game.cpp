#include "Game.h"
#include "App.h"
#include <iostream>
#include <SFML/Graphics.hpp>


void Game::Update()
{
	App::instance().Draw();

	app->GetWindow()->setPosition(Vector2i(50,50));

	//call update for all other gameobjects	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		std::cout << "[ " << app->GetWindow()->getPosition().x << " , " << app->GetWindow()->getPosition().y << std::endl;
	}


}

void Game::Draw()
{
	//call update for all other gameobjects	
}



Game::Game()
{

	app->instance();

}


Game::~Game()
{
}
