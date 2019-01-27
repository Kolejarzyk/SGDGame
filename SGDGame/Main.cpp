#include "SDL.h"

#include "Game.h"

Game *game = nullptr;
int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;

	Uint32 frameStart;	
	int frameTime;
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double dt = 0;

	game = new Game();

	game->init("SGDGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->running())
	{
	
		frameStart = SDL_GetTicks();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
		

		game->handleEvents();
		game->update();
		game->render();

		
	}

	game->clean();
	return 0;
}