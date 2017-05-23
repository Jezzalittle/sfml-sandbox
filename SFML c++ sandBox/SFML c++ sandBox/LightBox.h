#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Blocks;



class LightBox : GameObject
{
public:
	LightBox(Game* a_game, Vector2f a_pos);
	~LightBox();

	void Update(float deltaTime);
	void Draw(RenderWindow * renderer);
	void getBoxes(Blocks* blocksArray, int length);



	void DrawLines(RenderWindow * renderer);

private:
	Vector2f newPos;
	bool drawLines;
	std::vector<Blocks*> blocks;
	sf::RectangleShape light;
	Raycast* ray;

};

class Raycast
{
public:
	Raycast(Vector2f v2, float a_rot);
	void setRot(Vector2f vec);
	Vector2f pos;

	~Raycast();
	Vector2f LineIntersectionPoint(Vector2f ls1, Vector2f le1, Vector2f ls2, Vector2f le2);
private:
	float rot;

	Vector2f rotvec;

};