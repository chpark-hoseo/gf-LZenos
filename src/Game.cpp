#include "Game.h"


Game::Game()
{
	_window = nullptr;
	_renderer = nullptr;
	
	_isRunning = false;

	_texture = nullptr;
}
Game::~Game()
{
	if (IsRunning())
	{
		_isRunning = false;
		Clean();
	}
}

bool Game::Init(const char* title, int x_pos, int y_pos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		_window = SDL_CreateWindow(
			title,
			x_pos,
			y_pos,
			width, height,
			flags
		);

		if (_window != 0)
		{
			_renderer = SDL_CreateRenderer(_window, -1, 0);
			if (_renderer != 0)
			{
				SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
			}
			else
				return false;
		}
		else
			return false;
	}


	SDL_Surface* temp_surface = SDL_LoadBMP("Assets/rider.bmp");
	if (!temp_surface)
		return false;
	_texture = SDL_CreateTextureFromSurface(_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	SDL_QueryTexture(_texture, NULL, NULL, &_sourceRect.w, &_sourceRect.h);
	_targetRect.w = _sourceRect.w;
	_targetRect.h = _sourceRect.h;
	_targetRect.x = _sourceRect.x = 0;
	_targetRect.y = _sourceRect.y = 0;
	
	_isRunning = true;
	return true;
}
void Game::Update()
{

}
void Game::Render()
{
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, _texture, &_sourceRect, &_targetRect);
	SDL_RenderPresent(_renderer);
}

bool Game::IsRunning() const
{
	return _isRunning;
}

void Game::HandleEvents()
{
	SDL_Event e;
	if (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			_isRunning = false;
			break;
		}
	}
}

void Game::Clean()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}