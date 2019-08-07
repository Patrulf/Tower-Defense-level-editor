#pragma once
#include <map>
#include <SDL.h>
#include <vector>
#include "Sprite.h"

class Texture;
class Renderer;


//could be called textureManager? idk.
class SpriteManager
{
public:
	SpriteManager(Renderer* p_renderer);
	~SpriteManager();

	std::shared_ptr<Sprite> CreateSprite(std::string& p_textureFilePath);
	void RemoveSprite(Sprite* p_sprite);
private:
	Renderer* _renderer;
	std::map<std::string, Texture*> _textures;
	//std::vector<std::shared_ptr<Sprite>> _sprites; //change into a shared pointer.
};

