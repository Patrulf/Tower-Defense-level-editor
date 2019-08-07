#include "stdafx.h"
#include "GridTile.h"
#include "Vec2.h"
#include "DrawManager.h"
#include "ServiceLocator.h"
#include "SpriteManager.h"

GridTile::GridTile(std::string p_filePath,int p_x, int p_y, int p_size) :
	x{p_x},
	y{p_y},
	size{p_size}
{
	drawManager = ServiceLocator<DrawManager>::GetService();
	spriteManager = ServiceLocator<SpriteManager>::GetService();

	_sprite = spriteManager->CreateSprite(p_filePath);

	SDL_Rect position = { p_x,p_y,size,size };
	_sprite->SetRect(position);
}


GridTile::~GridTile() {

}

void GridTile::Draw() {
	drawManager->DrawSprite(_sprite.get());
}
