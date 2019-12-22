#include "stdafx.h"
#include "Font.h"
#include "ServiceLocator.h"
#include "Renderer.h"

Font::Font(std::string p_filePath, Uint32 p_size) {
	//_font = TTF_OpenFont(p_filePath.c_str(), p_size);
	
	_renderer = ServiceLocator<Renderer>::GetService();

	_font = FC_CreateFont();
	FC_LoadFont(_font, _renderer->GetRenderer(), p_filePath.c_str(), p_size,FC_MakeColor(255,0,0,255),TTF_STYLE_NORMAL);

	if (_font == nullptr) {
		throw(std::runtime_error("Could not init font"));
	}
}


//todo: change it so that one font -> more than one text.
void Font::Draw() {
	FC_Draw(_font, _renderer->GetRenderer(), 0, 0, "Hello world");
	FC_Draw(_font, _renderer->GetRenderer(), 100, 0, "Hello worldsss");
}

FC_Font* Font::GetFont() {
	return _font;
}

Font::~Font() {
	FC_FreeFont(_font);
	//TTF_CloseFont(_font);
}