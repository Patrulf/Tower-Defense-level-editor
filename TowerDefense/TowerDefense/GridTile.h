#pragma once
#include <memory>
#include "Sprite.h"

class DrawManager;
class SpriteManager;

class GridTile
{
public:
	GridTile(std::string p_filePath,int p_x,int p_y, int p_size);
	~GridTile();
	void Draw();

private:

	int x;
	int y;
	int size; //in pixels
	std::shared_ptr<Sprite> _sprite;

	DrawManager* drawManager;
	SpriteManager* spriteManager;
};

