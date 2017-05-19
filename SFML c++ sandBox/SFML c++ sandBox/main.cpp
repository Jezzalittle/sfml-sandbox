#include <SFML/Graphics.hpp>
#include "App.h"
#include "Application.h"

void main()
{
	App app;

	//set m_instance to the address of app
	App::m_instance = &app;

	app.Start();


	Application* application = new Application();
	application->execute();
	delete application;

}
