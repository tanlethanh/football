#include "Game.h"
#include <iostream>
#include <time.h>

Game *game = nullptr;

int main(int argc, char *argv[])
{
	srand(time(NULL));
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Football", 964, 632, false);

	std::cout << "starting game loop" << std::endl;

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}