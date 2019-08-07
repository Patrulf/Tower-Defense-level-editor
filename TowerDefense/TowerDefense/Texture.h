#pragma once
#include <SDL.h>
#include <string>

class Texture
{
public:
	Texture(SDL_Renderer* p_renderer, std::string p_filePath);
	~Texture();

	SDL_Texture* GetTexture();
private:
	SDL_Texture * _texture;
};

