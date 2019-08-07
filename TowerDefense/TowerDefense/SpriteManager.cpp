#include "stdafx.h"
#include "SpriteManager.h"
#include "Texture.h"
#include "Sprite.h"
#include <algorithm>
#include "Renderer.h"

SpriteManager::SpriteManager(Renderer* p_renderer) {
	_renderer = p_renderer;
}

SpriteManager::~SpriteManager()
{
	for (auto it = _textures.begin(); it != _textures.end(); it++)
	{
		delete it->second;
		it->second = nullptr;
	}
	_textures.clear();
}

std::shared_ptr<Sprite> SpriteManager::CreateSprite(std::string& p_filePath)
{
	auto it = _textures.find(p_filePath);
	if (it == _textures.end())
	{
		Texture* texture = new Texture(_renderer->GetRenderer(), p_filePath);
		_textures.insert(std::pair<std::string,Texture*>(p_filePath,texture));
	}

	std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(_textures[p_filePath], 100, 100, 100, 100);

	return std::move(sprite);
}
