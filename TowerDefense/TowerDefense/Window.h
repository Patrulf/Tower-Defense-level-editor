#pragma once
#include <SDL.h>


class Window
{
public:
	Window(const char* p_title, int p_x, int p_y, int p_w, int p_h);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(Window&) = delete;
	
	SDL_Window* GetWindow();
	void SetPosition(int p_x, int p_y);

private:
	SDL_Window * _window;
};

