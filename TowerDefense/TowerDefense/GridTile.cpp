#include "stdafx.h"
#include "GridTile.h"
#include "Vec2.h"
#include "DrawManager.h"
#include "ServiceLocator.h"
#include "SpriteManager.h"
#include <cmath>

GridTile::GridTile(std::string p_filePath,int p_x, int p_y, int p_size) :
	x{p_x},
	y{p_y},
	size{p_size},
	xScale{1.0f},
	yScale{1.0f},
	spriteFilePath{p_filePath}
{
	drawManager = ServiceLocator<DrawManager>::GetService();
	spriteManager = ServiceLocator<SpriteManager>::GetService();

	_sprite = spriteManager->CreateSprite(p_filePath);

	SDL_Rect position = { p_x,p_y,size,size };
	_sprite->SetRect(position);
}


GridTile::~GridTile() {

}

Vec2 GridTile::GetPosition() {
	Vec2 position = { static_cast<float>(x),static_cast<float>(y) };
	return position;
}

std::string GridTile::GetSpriteFilePath() {
	return spriteFilePath;
}

void GridTile::SetSprite(std::string p_filePath) {
	spriteFilePath = p_filePath;
	_sprite = spriteManager->CreateSprite(p_filePath);
	SDL_Rect position = { x,y,size,size };
	_sprite->SetRect(position);
}

void GridTile::SetScale(float p_xScale, float p_yScale) {
	xScale = p_xScale;
	yScale = p_yScale;
	SDL_Rect rect = { x,y,static_cast<int>(round(size*p_xScale)), static_cast<int>(round(size*p_yScale)) };
	_sprite->SetRect(rect);
}

void GridTile::Draw() {
	drawManager->DrawSprite(_sprite.get());
}


