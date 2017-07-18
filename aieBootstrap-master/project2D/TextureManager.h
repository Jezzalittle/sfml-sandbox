#pragma once

#include <vector>
#include <iostream>
#include "Texture.h"
#include "Vector3.h"

class aie::Texture;



struct Color
{

	Color(int a_r, int a_g, int a_b);

	int r;
	int g;
	int b;
};


class TextureManager
{
public:
	TextureManager();
	void Add(aie::Texture* texture);
	aie::Texture* FindByFileName(std::string tag);
	~TextureManager();

	void printTextureArray();

	Color* GetRed();
	Color* GetGreen();
	Color* GetPink();
	Color* GetBlue();

	Color* GetRandomColor();



private:
	Color* red;
	Color* green;
	Color* pink;
	Color* blue;
	void PullTextures();
	
	std::vector<Vector3*> lightColors;

	std::vector<aie::Texture*> textureArray;
	

};
