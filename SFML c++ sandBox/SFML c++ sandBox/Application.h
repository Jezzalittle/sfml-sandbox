#pragma once
class Application
{
public:
	Application();
	~Application();

	void execute();

private:
	void start();
	void update(float deltaTime);
	void draw(/*2DRenderer*/);
	void shutdown();

};

