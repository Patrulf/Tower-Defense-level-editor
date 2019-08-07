#pragma once
#include "State.h"

class GameObject;
class DrawManager;
class SpriteManager;
class Grid;
class Menu;
class InputManager;
class CollisionManager;

class LevelCreationState : public State
{
public:
	LevelCreationState(InputManager* p_inputManager, SpriteManager* p_spriteManager, DrawManager* p_drawManager, CollisionManager* p_collisionManager);
	~LevelCreationState();

	void Draw();
	void Update();
	void Enter();
	void Exit();


	//button should just take a callback with variadic number of arguments tbh.
	void SelectDirt();
	void SelectGrass();
	void SelectWater();

private:

	CollisionManager* collisionManager;
	InputManager* inputManager;
	SpriteManager* spriteManager;
	DrawManager* drawManager;
	Grid* grid;
	Menu* selectionMenu;
	GameObject* currentSelection;

};

