#pragma once
#include "json.hpp"


class Grid;
using json = nlohmann::json;

class FileManager
{
public:
	FileManager();
	~FileManager();

	void SaveGrid(Grid* p_grid);

	void LoadGrid(std::string p_levelFilePath, Grid* p_grid);
	json gridSave;
};

