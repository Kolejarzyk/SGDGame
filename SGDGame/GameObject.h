#pragma once

#include "Game.h"
class GameObject
{
public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();
	void Update();
	void Render();
	void left();
	void right();
	void jump();
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};