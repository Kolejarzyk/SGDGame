#include "SDL.h"

#include "Game.h"

Game *game = nullptr;
int main(int argc, char *argv[])
{
	game = new Game();

	game->init("SGDGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();

	}

	game->clean();
	return 0;
}