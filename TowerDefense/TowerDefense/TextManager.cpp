#include "stdafx.h"
#include "TextManager.h"


TextManager::TextManager()
{
}

TextManager::~TextManager()
{
	//LOOP THROUGH FONTS AND DELETE.
	for (auto it = _fonts.begin(); it != _fonts.end(); it++)
	{
		delete it->second;
		it->second = nullptr;
	}
	_fonts.clear();
}

void TextManager::CreateFont(std::string p_fontKey, std::string p_filePath, Uint32 p_size) {
	Font* font = new Font(p_filePath, p_size);
	_fonts.insert(std::make_pair(p_fontKey, font));//needs to be a pointer or we need a copyconstructor, or maybe move constructor.	
}

void TextManager::CreateTextSnippet(std::string p_key, std::string p_text) {
	
}

void Draw() {

}
