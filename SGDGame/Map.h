#pragma once
#include "Game.h"

class Map{
public:
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();
private:
	SDL_Rect src, dest;
	SDL_Texture*  field;
	SDL_Texture*  berm;
	SDL_Texture*  cobweb;

	int map[20][25];

};