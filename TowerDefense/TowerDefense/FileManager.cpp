#include "stdafx.h"
#include "FileManager.h"
#include <fstream>
#include "Grid.h"

/**/
#include <iostream>
/**/
FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}


//we have gridtiles & gameobjects. those are the two types we are saving.

//how would we make sure to save&load things in the correct order?
//We should probably just have save grid & save gameObject
void FileManager::SaveGrid(Grid* p_grid) { //send in a gameobject instead of a string. 

	gridSave["Size"] = p_grid->GetSize();
	for (int i = 0; i < p_grid->GetSize(); i++) {
		//access the tile.
		std::shared_ptr<GridTile> ptr = p_grid->AccessGridTileFromIndex(i);
		//Now store whatever you need in the json file.
		gridSave["positionX" + std::to_string(i)] = ptr->GetPosition().x;
		gridSave["positionY" + std::to_string(i)] = ptr->GetPosition().y;
		gridSave["Sprite" + std::to_string(i)] = ptr->GetSpriteFilePath();
	}
	std::ofstream file("Level");
	file << gridSave;
}

//Functionality that creates the grid tiles should probably come from within the grid and not here.
void FileManager::LoadGrid(std::string p_levelFilePath, Grid* p_grid) {
	std::ifstream file("Level");
	file >> gridSave;
	for (int i = 0; i < gridSave["Size"]; i++) {
		//create a grid tile,
		float positionX = gridSave["positionX" + std::to_string(i)];
		float positionY = gridSave["positionY" + std::to_string(i)];
		std::string filePath = gridSave["Sprite" + std::to_string(i)];
		p_grid->CreateGridTile(filePath, positionX, positionY);
	}
}
