#pragma once

#include "../include/main.h"


class Game
{
private:
	class SDL_Window* _window;
	class SDL_Renderer* _renderer;

	bool _isRunning;

	class SDL_Texture* _texture;

	SDL_Rect _sourceRect;
	SDL_Rect _targetRect;

public:
	Game();
	~Game();

	bool Init(const char* title, int x_pos, int y_pos, int width, int height, int flags);
	void Update();
	void Render();

	bool IsRunning() const;
	void HandleEvents();
	void Clean();
};