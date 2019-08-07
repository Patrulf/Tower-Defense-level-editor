#include "stdafx.h"
#include "LevelCreationState.h"

#include "DrawManager.h"
#include "SpriteManager.h"
#include "InputManager.h"
#include "CollisionManager.h"

#include "Grid.h"
#include "Menu.h"

#include "GameObject.h"

/*
	Next up: Allow mouse clicks to work with buttons.
*/

//todo: figure out how to sort out window size dimensions.
LevelCreationState::LevelCreationState(InputManager* p_inputManager,SpriteManager* p_spriteManager,
	DrawManager* p_drawManager, CollisionManager* p_collisionManager) 
{
	spriteManager = p_spriteManager;
	drawManager = p_drawManager;
	inputManager = p_inputManager;
	collisionManager = p_collisionManager;

	Vec2 pos(10.0f,10.0f);
	grid = new Grid(pos,33,31);
	grid->InitGrid();
	selectionMenu = new Menu(inputManager, spriteManager, drawManager, collisionManager);
	//We will create 3 buttons that allows us to modify the sprite used at a certain tile of the grid.
	//and a button that allows us to save the map.
	selectionMenu->CreateButton("../Assets/Dirt.png", p_spriteManager, p_drawManager, std::bind(&LevelCreationState::SelectDirt, this));
	selectionMenu->CreateButton("../Assets/Water.png", p_spriteManager, p_drawManager, std::bind(&LevelCreationState::SelectWater, this));
	selectionMenu->CreateButton("../Assets/Grass.png", p_spriteManager, p_drawManager, std::bind(&LevelCreationState::SelectGrass, this));
	Vec2 buttonPos = { 600.0f,100.0f };
	selectionMenu->SetButtonPosition(0, buttonPos);
	Vec2 buttonPos2 = { 700,100.0f };
	selectionMenu->SetButtonPosition(1, buttonPos2);
	Vec2 buttonPos3 = { 600, 150 };
	selectionMenu->SetButtonPosition(2,buttonPos3);

}
LevelCreationState::~LevelCreationState(){}

void LevelCreationState::SelectWater() {}

void LevelCreationState::SelectDirt() {}

void LevelCreationState::SelectGrass() {}

void LevelCreationState::Update() {
	selectionMenu->Update();
}

void LevelCreationState::Draw() {
	grid->Draw();
	selectionMenu->Draw();
}

void LevelCreationState::Enter() {
	//problem in navigate menu after entering.
}

void LevelCreationState::Exit() {

}