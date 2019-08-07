#pragma once
#include "Vec2.h"
#include <memory>
#include <vector>
#include <string>
#include "GridTile.h"
#include "Sprite.h"

class Grid
{
public:
	Grid(Vec2 p_pos, int p_width, int p_height);
	~Grid();
	std::shared_ptr<GridTile> AccessGridTileFromIndex(int p_x, int p_y);
	GridTile* AccessGridTileFromPosition(Vec2 p_position);
	Vec2 TranslateToGridSpace(Vec2 p_position);

	void InitGrid();
	void Draw();
private:
	std::vector<std::shared_ptr<GridTile>> gridTiles;

	//std::shared_ptr<Sprite> sprite;
	Vec2 pos;
	int width; //should be like xCells.
	int height; //should be like yCells.	
};

