#pragma once

class Game
{
private:
	class SDL_Window* _window;
	class SDL_Renderer* _renderer;

	bool _isRunning;

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