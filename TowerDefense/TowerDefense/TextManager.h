#pragma once
#include <memory>
#include <vector>
#include <string>
#include <map>
#include "Font.h"

class TextManager
{
public:
	TextManager();
	~TextManager();

	void CreateFont(std::string p_fontKey, std::string p_filePath, Uint32 p_size);
	void CreateTextSnippet(std::string p_fontKey, std::string p_text);
	void Draw();
private:
	std::map<std::string, Font*> _fonts;
};

