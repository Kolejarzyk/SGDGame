#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Enemy.h"
#include "Feather.h"
#include "SDL_ttf.h"
#include <string> 
#include <random>

GameObject* bird;
Feather* feather;
Enemy* enemy;
Enemy* enemy1;
Map* map;
SDL_Renderer* Game::renderer = nullptr;
Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!.." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	bird = new GameObject("Assets/bird.png", 320, 449);
	feather = new Feather("Assets/feather.png", 450, 449);
	enemy = new Enemy("Assets/enemy.png", 110, 449, 0.5f);
	map = new Map();
	enemy1 = new Enemy("Assets/enemy.png", 110, 123, 0.5f);
	
	
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:  bird->left(); break;
		case SDLK_RIGHT: bird->right(); break;
		case SDLK_UP:    bird->jump(); break;
		}
		break;
	default:	
			bird ->none();
	    break;
	}
}
void Game::update()
{
	
	bird->Update();
	feather->Update();
	enemy->Update();
	enemy1->Update();
	if(bird->check_collision(bird->get(), feather->get()))
	{
		cnt += 1;
		std::cout << cnt;
		std::random_device rd;
		std::mt19937 eng(rd()); 
		std::uniform_int_distribution<> distr(0, 750); // define the range
		std::uniform_int_distribution<> distr1(0, 449); // define the range
		feather = new Feather("Assets/feather.png", distr(eng), distr1(eng));
	}

	if(bird->check_collision(bird->get(), enemy->get()))
	{
		bird = new GameObject("Assets/bird.png", 320, 449);
		feather = new Feather("Assets/feather.png", 450, 449);
		enemy = new Enemy("Assets/enemy.png", 110, 449, 0.1f);
		enemy1 = new Enemy("Assets/enemy.png", 110, 123, 0.5f);
		map = new Map();
		cnt = 0;
		
	}

	if (bird->check_collision(bird->get(), enemy1->get()))
	{
		bird = new GameObject("Assets/bird.png", 320, 449);
		feather = new Feather("Assets/feather.png", 450, 449);
		enemy = new Enemy("Assets/enemy.png", 110, 449,0.1f);
		enemy1 = new Enemy("Assets/enemy.png", 110, 123,0.5f);
		map = new Map();
		cnt = 0;

	}

	if (map->checkCollision(bird->get()))
	{
		printf("It's work");
	}
	

	
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();	
	TTF_Init();
	TTF_Font* Times = TTF_OpenFont("Assets/times.ttf", 34);
	SDL_Color White = { 0,0,0 };

	std::string score = "Score: ";
	std::string count = std::to_string(cnt);
	score = score + count;
	SDL_Surface* surfacemessage = TTF_RenderText_Solid(Times, score.c_str() , White);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfacemessage);
	SDL_Rect Message_rect;
	Message_rect.x = 0;
	Message_rect.y = 500;
	Message_rect.w = 100;
	Message_rect.h = 100;
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	bird->Render();
	feather->Render();
	enemy->Render();
	enemy1->Render();
	SDL_RenderPresent(renderer);


}

void Game :: clean()
{
	TTF_Quit();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << " Game Cleaned" << std::endl;
}