#include <SDL2/SDL.h>

#include "Game.h"


int main(int argc, char* args[])
{
	Game* game = new Game();

	game->Init("K-Move SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	while (game->IsRunning())
	{
		game->Update();
		game->Render();
	}

	delete game;

	return 0;
}