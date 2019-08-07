#pragma once
#include <SDL.h>
#include "Texture.h"

class Sprite
{
public:
	Sprite(Texture* p_texture, int p_x, int p_y, int p_w, int p_h);
	~Sprite();

	Texture* GetTexture();
	SDL_Rect GetRect();
	void SetRect(SDL_Rect& p_rect);

private:
	Texture* _texture; //pointer? Yes, here we need a pointer.
	SDL_Rect _rect;
};

