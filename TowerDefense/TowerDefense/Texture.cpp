#include "stdafx.h"
#include "Texture.h"
#include <stdexcept>
#include <SDL_image.h>
#include "Surface.h"

#include <iostream>

Texture::Texture(SDL_Renderer* p_renderer, std::string p_filePath)
{
	if (p_renderer == nullptr)
	{
		throw(std::runtime_error("Could not init texture as renderer was nullptr"));
	}
	Surface surface(p_filePath);
	_texture = SDL_CreateTextureFromSurface(p_renderer, surface.GetSurface() );
}

Texture::~Texture()
{
	SDL_DestroyTexture(_texture);
}

/*Texture::Texture(const Texture& p_other) {
	std::cout << "Copy constructor" << '\n';
}*/


SDL_Texture* Texture::GetTexture() {
	return _texture;
}
