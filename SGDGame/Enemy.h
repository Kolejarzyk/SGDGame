#pragma once

#include "Game.h"
#include "Map.h"
#include "Vec.h"
class Enemy
{
public:
	Enemy(const char* texturesheet, float x, float y, float velx);
	~Enemy();
	void Update();
	void Render();
	bool check_collision(SDL_Rect aPlayer, SDL_Rect oneAsteroid);
	SDL_Rect  get();
private:
	Vec position;
	Vec velocity;
	Vec gravity;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	int move_direction = 0;
	float velx = 0;
};