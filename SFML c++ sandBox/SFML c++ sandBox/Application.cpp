#include "Application.h"



Application::Application()
{
}


Application::~Application()
{
}

void Application::execute()
{
	start();

	while (true)
	{
		update(0.0f);

		draw();
	}

	shutdown();
}

void Application::update(float deltaTime)
{
	//game.update(deltaTime)
}

void Application::draw()
{
	//game.draw();
}