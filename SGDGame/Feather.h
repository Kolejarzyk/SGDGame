#pragma once

#include "Game.h"
#include "Map.h"
#include "Vec.h"
class Feather
{
public:
	Feather(const char* texturesheet, float x, float y);
	~Feather();
	void Update();
	void Render();
	bool check_collision(SDL_Rect aPlayer, SDL_Rect oneAsteroid);
	SDL_Rect get();
private:
	Vec position;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};