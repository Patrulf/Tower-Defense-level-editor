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
	gridWidth(p_width),
	gridHeight(p_height),
	cellWidth(32.0f),
	cellHeight(32.0f)
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

void Grid::CreateGridTile(std::string p_filePath, float p_x, float p_y) {
	std::shared_ptr<GridTile> ptr = std::make_shared<GridTile>(p_filePath,p_x,p_y,32);
	//Double check this!                                              MAGIC NUMBER^
	gridTiles.push_back(ptr);
}

void Grid::Clear() {
	gridTiles.clear();
}


void Grid::InitGrid() {

	int x = 0;
	int y = 0;

	for (int i = 0; i < gridHeight * gridWidth; i++) {
		//x*width, y*width
		//x*width*0.5f + pos.x, y*height*0.5f + pos.y

		std::string filePath = "../Assets/Dirt.png";
		std::shared_ptr<GridTile> ptr = std::make_shared<GridTile>(filePath,x*cellWidth,y*cellHeight,32);
		//                                                                     assumes width = height ^
		gridTiles.push_back(std::move(ptr));

		x++;
		if (x % (gridWidth) == 0 && x > 0) {
			y++;
			x = 0;
		}
	}
}

int Grid::GetSize() {
	return gridWidth * gridHeight;
}

void Grid::ScaleGrid(float p_xScale, float p_yScale) {	
	for (auto it = gridTiles.begin(); it != gridTiles.end(); it++) {
		(*it)->SetScale(p_xScale, p_yScale);
	}
}

//this should return two ints but whatever.
Vec2 Grid::TranslateToGridSpace(Vec2 p_position) {
	//todo:
	Vec2 bajs(0.0f, 0.0f);
	return bajs;
}

Vec2 Grid::GetPosition() {
	return pos;
}

int Grid::GetWidth() {
	return gridWidth;
}

int Grid::GetHeight() {
	return gridHeight;
}

std::shared_ptr<GridTile> Grid::AccessGridTileFromIndex(int p_i) {
	if (p_i < 0 || p_i >= gridWidth * gridHeight) {
		return nullptr;
	}
	return gridTiles[p_i];
}

std::shared_ptr<GridTile> Grid::AccessGridTileFromIndex(int p_x,int p_y)
{
	if (p_x >= gridWidth || p_x < 0 || p_y >= gridHeight || p_x < 0) {
		return nullptr;
	}
	return gridTiles[p_y*gridWidth + p_x];
}

std::shared_ptr<GridTile> Grid::AccessGridTileFromPosition(Vec2 p_position) {
	//TODO:
	//Add offset with position, if we are using positions.
	int xIndex = static_cast<int>(p_position.x/cellWidth);
	int yIndex = static_cast<int>(p_position.y/cellHeight);

	return AccessGridTileFromIndex(xIndex, yIndex);
}