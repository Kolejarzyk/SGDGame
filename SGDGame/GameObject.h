#pragma once

#include "Game.h"
#include "Map.h"
#include "Vec.h"
class GameObject
{
public:
	GameObject(const char* texturesheet, float x, float y);
	~GameObject();
	void Update();
	void Render();
	void left();
	void right();
	void jump();
	void none();
	bool check_collision(SDL_Rect aPlayer, SDL_Rect oneAsteroid);	
	SDL_Rect get();
 private:
	const int jumpHeight = 10;
	Vec position;
	Vec velocity;
	Vec gravity;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	float dt = 1 / 60.0;
};