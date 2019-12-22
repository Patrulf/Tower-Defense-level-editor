#pragma once
#include "State.h"

class GameObject;
class DrawManager;
class SpriteManager;
class Grid;
class Menu;
class InputManager;
class CollisionManager;
class FileManager;

enum CurrentSprite {
	dirt,
	grass,
	water
};

class LevelCreationState : public State
{
public:
	LevelCreationState(InputManager* p_inputManager, SpriteManager* p_spriteManager, DrawManager* p_drawManager, 
		CollisionManager* p_collisionManager, FileManager* p_fileManager);
	~LevelCreationState();

	void Draw();
	void Update();
	void Enter();
	void Exit();


	//button should just take a callback with variadic number of arguments tbh.
	// tbh, these should be in their own class somewhere, no idea what to call said class though.
	// and also, if any of this should be handled by the collisionmanager.
	//it somewhat feels like the grids duty, but also not. what we select shouldn't be the grid responsibility.
	//but maybe the placement should be?
	void SelectDirt();
	void SelectGrass();
	void SelectWater();
	void PlaceOnGrid();
	void SaveLevel();
	void LoadLevel();
	//

private:

	FileManager* fileManager;
	CollisionManager* collisionManager;
	InputManager* inputManager;
	SpriteManager* spriteManager;
	DrawManager* drawManager;
	Grid* grid;
	Menu* selectionMenu;
	CurrentSprite currentSprite;
};

