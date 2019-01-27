#pragma once
#include "Game.h"

class Map{
public:
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();
	bool checkCollision(SDL_Rect entity);
private:
	SDL_Rect src, dest;
	SDL_Texture*  field;
	SDL_Texture*  berm;
	SDL_Texture*  cobweb;
	SDL_Texture*  sky;
	int map[20][25];

};