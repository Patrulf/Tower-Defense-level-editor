#pragma once
#include "State.h"

class DrawManager;
class SpriteManager;
class InputManager;

class Menu;
class LevelManager;
class CollisionManager;

class MainMenuState : public State
{
public:
	MainMenuState(InputManager* p_inputManager, SpriteManager* p_spriteManager, DrawManager* p_drawManager,
		LevelManager* p_levelManager, CollisionManager* p_collisionManager);
	~MainMenuState();

	void Draw();
	void Update();
	void Enter();
	void Exit();

	void GoToLevelCreationState();
	void QuitGame();

private:

	CollisionManager* collisionManager;
	SpriteManager* spriteManager;
	DrawManager* drawManager;
	InputManager* inputManager;
	Menu* menu;
	LevelManager* levelManager;
};

