#pragma once
#include <memory>
#include "Sprite.h"
#include "Vec2.h"

class DrawManager;
class SpriteManager;

class GridTile
{
public:
	GridTile(std::string p_filePath,int p_x,int p_y, int p_size);
	~GridTile();
	void Draw();
	void SetScale(float p_x, float p_y);
	void SetSprite(std::string p_filePath);
	std::string GetSpriteFilePath();
	Vec2 GetPosition();
private:

	std::string spriteFilePath;
	float xScale;
	float yScale;
	int x;
	int y;
	int size; //in pixels
	std::shared_ptr<Sprite> _sprite;

	DrawManager* drawManager;
	SpriteManager* spriteManager;
};

