#include "App.h"




App::App()
{

}

void App::GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}


void App::Start()
{
	GetDesktopResolution(horizontal, vertical);
	window.setFramerateLimit(FPS);
	window.create(VideoMode(horizontal, vertical), "SFML works!");
	game = new Game();
	Update();
}




void App::Update()
{
	Clock clock;
	while (window.isOpen())
	{
		Time time = clock.restart();
		deltaTime = clock.getElapsedTime().asSeconds();
		
		game->Update();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		Draw();
	}
}

void App::Draw()
{

	window.clear();
	//game->Draw();

	window.display();
}

void App::StartUp()
{
}

RenderWindow * App::GetWindow()
{
	return &window;
}

float App::getDeltaTime()
{
	return deltaTime;
}

App::~App()
{
}

