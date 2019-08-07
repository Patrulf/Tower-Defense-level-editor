#include "stdafx.h"
#include "Grid.h"
#include "Plane.h"
#include <math.h>
#include "ServiceLocator.h"
#include "SpriteManager.h"

/*::::::::test::::::::*/
#include <iostream>
/*::::::::::::::::::*/
Grid::Grid(Vec2 p_pos,int p_width, int p_height) :
	pos(p_pos),
	width(p_width),
	height(p_height)
{
}

Grid::~Grid()
{
}

void Grid::Draw() {
	for (auto it = gridTiles.begin(); it != gridTiles.end(); it++) {
		(*it)->Draw();
	}
}

void Grid::InitGrid() {

	int x = 0;
	int y = 0;

	for (int i = 0; i < height * width; i++) {
		//x*width, y*width
		//x*width*0.5f + pos.x, y*height*0.5f + pos.y

		std::string filePath = "../Assets/Dirt.png";
		std::shared_ptr<GridTile> ptr = std::make_shared<GridTile>(filePath,x*32,y*32,32);
		gridTiles.push_back(std::move(ptr));

		x++;
		if (x % (width) == 0 && x > 0) {
			y++;
			x = 0;
		}
	}
}


//this should return two ints but whatever.
Vec2 Grid::TranslateToGridSpace(Vec2 p_position) {
	//todo:
	Vec2 bajs(0.0f, 0.0f);
	return bajs;
}

std::shared_ptr<GridTile> Grid::AccessGridTileFromIndex(int p_x,int p_y)
{
	if (p_x > width || p_x < 0 || p_y > height || p_x < 0) {
		return nullptr;
	}
	return gridTiles[p_y*width + p_x];
}

GridTile* Grid::AccessGridTileFromPosition(Vec2 p_position) {
	//TODO:
	float x = (roundf(p_position.x));
	float y = (roundf(p_position.y));

	//now we need to translate it into grid coordinates.
	x += pos.x - width*0.5f; //what if width is an even number? then it'll take care of itself due to rounding so whatever.
	y += pos.y - height*0.5f;

	//Now we need to find grid through position if we want to do it this way.
	return nullptr;
}