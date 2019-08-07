#pragma once
#include <SDL.h>
#include "Window.h"
#include "Display.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator=(Renderer&) = delete;

	void DrawBG();
	void Draw(SDL_Rect& p_rect);
	void Present();
	SDL_Renderer* GetRenderer();

private:
	Window _window;
	SDL_Renderer * _renderer;
	Display _display;
};

