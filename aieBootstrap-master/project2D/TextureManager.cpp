#include "TextureManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

TextureManager::TextureManager()
{
	red = new Color(255, 0, 0);
	green = new Color(0,255,0);
	blue = new Color(0,38,255);
	pink = new Color(255,0,220); 
	PullTextures();
}

void TextureManager::Add(aie::Texture* texture)
{
	textureArray.push_back(texture);
}

aie::Texture * TextureManager::FindByFileName(std::string tag)
{
	for (int i = 0; i < textureArray.size(); i++)
	{
		if (textureArray[i]->getFilename() == tag)
		{
			return textureArray[i];
		}
	}

	return nullptr;
}


TextureManager::~TextureManager()
{

}

void TextureManager::printTextureArray()
{
	for (int i = 0; i < textureArray.size(); i++)
	{
		cout << textureArray[i] << endl;
	}
}

Color * TextureManager::GetRed()
{
	return red;
}

Color * TextureManager::GetGreen()
{
	return green;
}

Color * TextureManager::GetPink()
{
	return pink;
}

Color * TextureManager::GetBlue()
{
	return blue;
}

Color * TextureManager::GetRandomColor()
{
	srand(time(NULL));
	int randNum = rand() % 4 + 1;

	if (randNum == 1)
	{
		return GetBlue();
	}
	else if (randNum == 2)
	{
		return GetRed();
	}
	else if (randNum == 3)
	{
		return GetGreen();
	}
	else
	{
		return GetPink();
	}
	return nullptr;
}

void TextureManager::PullTextures()
{
	string line;
	ifstream myfile("./textures.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			aie::Texture* x = new  aie::Texture(line.c_str());
			textureArray.push_back(x);
			std::cout << line << std::endl;
		}
		myfile.close();
	}



}

Color::Color(int a_r, int a_g, int a_b)
{

	r = a_r;
	g = a_g;
	b = a_b;
}
