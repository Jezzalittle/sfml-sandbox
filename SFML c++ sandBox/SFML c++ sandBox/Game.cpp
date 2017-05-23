#include "Game.h"
#include "Blocks.h"
#include <iostream>
#include "LightBox.h"
#include <vector>
#include "App.h"

void Game::Start()
{

	lightbox = nullptr;
	amountOfBlocks = 0;
}

int Game::getWidth()
{
	return width;
}

int Game::getHeigth()
{
	return height;
}

std::vector < Blocks* > Game::GetBoxArray()
{
	return boxArray;
}

void Game::Update(float deltaTime)
{

	if (lightbox != nullptr)
	{
		lightbox->Update(deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && edgeCount == 1)
	{
		tl = sf::Vector2f(sf::Mouse::getPosition(*rw).x, sf::Mouse::getPosition(*rw).y);
		edgeCount = 2;

	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && edgeCount == 2)
	{
		br = sf::Vector2f(sf::Mouse::getPosition(*rw).x, sf::Mouse::getPosition(*rw).y);
		edgeCount = 3;
	}
	if (edgeCount == 3)
	{
		tr.y = tl.y;
		tr.x = br.x;
		bl.y = br.y;
		bl.x = tl.x;
		amountOfBlocks++;
		Blocks* newBox = new Blocks(tl,tr,bl,br);
		boxArray.push_back(newBox);
		edgeCount = 1;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		lightbox = new LightBox(this,(Vector2f)sf::Mouse::getPosition());

	}


}

void Game::Draw(sf::RenderWindow* a_window)
{
	if (once == false)
	{
		rw = a_window;
		once = true;
	}
	//call update for all other gameobjects	
	for (size_t i = 0; i < boxArray.size(); i++)
	{
		boxArray[i]->Draw(rw);
	}

	if (lightbox != nullptr)
	{
		lightbox->Draw(rw);
	}

}



int Game::getAmountOfBlocks()
{
	return amountOfBlocks;
}


Game::Game(App * a_app)
{
	edgeCount = 1;
	once = false;
	app = a_app;
	width = app->horizontal;
	height = app->vertical;
}

Game::~Game()
{
}


