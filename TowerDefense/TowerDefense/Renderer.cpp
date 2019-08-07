#include "stdafx.h"
#include "Renderer.h"
#include <stdexcept>
#include "Sprite.h"

Renderer::Renderer() :
	_display{},
	_window {"Title", 0, 0, 1080, 720} // fix magic numbers.
{
	_window.SetPosition(_display.GetDisplay().w / 2 - (1080 / 2 ), _display.GetDisplay().h / 2 - (720 / 2)); //fix magic numbers
	_renderer = SDL_CreateRenderer(_window.GetWindow(), -1,SDL_RENDERER_ACCELERATED);
	if (_renderer == nullptr)
	{
		throw(std::runtime_error("Renderer was nullptr"));
	}
}

SDL_Renderer* Renderer::GetRenderer()
{
	return _renderer;
}


Renderer::~Renderer()
{
	SDL_DestroyRenderer(_renderer);
}

void Renderer::DrawBG() {
	
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
}

void Renderer::Present()
{
	SDL_RenderPresent(_renderer);
}