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
	std::shared_ptr<GridTile> AccessGridTileFromIndex(int p_i);
	std::shared_ptr<GridTile> AccessGridTileFromPosition(Vec2 p_position);
	Vec2 TranslateToGridSpace(Vec2 p_position);

	void CreateGridTile(std::string p_filePath, float p_x, float p_y);
	void InitGrid();
	void ScaleGrid(float p_xScale, float p_yScale);	
	Vec2 GetPosition();
	int GetWidth();
	int GetHeight();
	int GetSize();
	void Clear();

	void Draw();

private:
	std::vector<std::shared_ptr<GridTile>> gridTiles;

	//std::shared_ptr<Sprite> sprite;
	Vec2 pos;
	int gridWidth; //should be like xCells.
	int gridHeight; //should be like yCells.	
	float cellWidth;
	float cellHeight;
};

