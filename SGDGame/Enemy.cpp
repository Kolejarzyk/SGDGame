#include "Enemy.h"
#include "TextureManager.h"
#include "Vec.h"

Enemy::Enemy(const char* texturesheet, float x, float y,float velx)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	position = Vec(x, y);
	velocity = Vec(0, 0);
	this->velx = velx;
}

Enemy::~Enemy()
{}

void Enemy::Update()
{

	position += velocity;
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;


	if (move_direction == 0)
	{
		velocity = velocity + Vec(velx,0);
	}
	else if (move_direction == 1)
	{
		velocity = velocity + Vec(-velx, 0);
	}
	
	

	
	position = position + velocity;
	if (position.y == 449)
	{
		position.y = 449;
	}
	if (position.x > 750)
	{
		position.x = 750;
		velocity = Vec(0, 0);
		move_direction = 1;
	}
	if (position.x < 0)
	{
		velocity = Vec(0, 0);
		position.x = 0;
		move_direction = 0;
	}
	destRect.x = position.x;
	destRect.y = position.y;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}



void Enemy::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}


bool Enemy::check_collision(SDL_Rect aPlayer, SDL_Rect oneAsteroid) {

	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = aPlayer.x;
	rightA = aPlayer.x + aPlayer.w;
	topA = aPlayer.y;
	bottomA = aPlayer.y + aPlayer.h;

	//Calculate the sides of rect B
	leftB = oneAsteroid.x;
	rightB = oneAsteroid.x + oneAsteroid.w;
	topB = oneAsteroid.y;
	bottomB = oneAsteroid.y + oneAsteroid.h;


	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

SDL_Rect Enemy::get()
{
	return destRect;
}


