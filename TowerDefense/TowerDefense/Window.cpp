#include "stdafx.h"
#include "Window.h"
#include <stdexcept>

Window::Window(const char* p_title, int p_x, int p_y, int p_w, int p_h)
{
	_window = SDL_CreateWindow(p_title, p_x, p_y, p_w, p_h, SDL_WINDOW_OPENGL);
	if (_window == nullptr)
	{
		throw(std::runtime_error("Window was nullptr"));
	}
}

Window::~Window()
{
	SDL_DestroyWindow(_window);
}

void Window::SetPosition(int p_x, int p_y)
{
	SDL_SetWindowPosition(_window, p_x, p_y);
}

SDL_Window* Window::GetWindow()
{
	return _window;
}