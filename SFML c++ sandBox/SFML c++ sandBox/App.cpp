#include "App.h"

void App::execute()
{
	Clock clock;
	Start();
	while (window.isOpen())
	{
		Time time = clock.restart();
		deltaTime = clock.getElapsedTime().asSeconds();

		game->Update(deltaTime);
		Draw(&window);
		Shutdown();
	}
}

App::App()
{
	GetDesktopResolution(horizontal, vertical);
	window.setFramerateLimit((unsigned int)FPS);
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	window.create(VideoMode(horizontal, vertical, desktop.bitsPerPixel), "2d Light Example",Style::Fullscreen);
	game = new Game(this);
	execute();
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
	horizontal = desktop.right - 30;
	vertical = desktop.bottom;
}

void App::Shutdown()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void App::Start()
{
	game->Start();
}

void App::Update(float deltaTime)
{
	game->Update(deltaTime);
}

void App::Draw(sf::RenderWindow* a_window)
{
	a_window->clear();
	game->Draw(a_window);
	a_window->display();
}

App::~App()
{
	delete game;
}

