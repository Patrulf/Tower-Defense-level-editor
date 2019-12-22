#pragma once
//#include "SDLInit.h"
#include <string>
#include "External/SDL_FontCache.h"

class Renderer;

class Font
{
public:
	Font(std::string p_filePath, Uint32 p_size);
	~Font();
	Font(const Font& p_font) = delete;
	Font& operator = (Font&) = delete;
	void Draw();
	//TTF_Font* GetFont();
	FC_Font* GetFont();

private:
	FC_Font* _font;
	Renderer* _renderer;
	//TTF_Font* _font;
};