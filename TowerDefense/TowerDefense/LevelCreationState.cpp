#include "stdafx.h"
#include "LevelCreationState.h"

#include "DrawManager.h"
#include "SpriteManager.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "FileManager.h"

#include "Grid.h"
#include "Menu.h"

#include "GameObject.h"
#include "Enter.h" //maybe just include command.h? idk.

/*TEST*/
#include <iostream>
/*TEST*/

/*
	Next up: Allow mouse clicks to work with buttons.
*/

//todo: figure out how to sort out window size dimensions.
LevelCreationState::LevelCreationState(InputManager* p_inputManager,SpriteManager* p_spriteManager,
	DrawManager* p_drawManager, CollisionManager* p_collisionManager, FileManager* p_fileManager) : 
	currentSprite(dirt)
{
	spriteManager = p_spriteManager;
	drawManager = p_drawManager;
	inputManager = p_inputManager;
	collisionManager = p_collisionManager;
	fileManager = p_fileManager;

	Vec2 pos(10.0f,10.0f);
	grid = new Grid(pos,23,23);
	grid->InitGrid();
	selectionMenu = new Menu(inputManager, spriteManager, drawManager, collisionManager);

	//should probably id the buttons through a string or something, when we get to loads of buttons we need to organise them properly.
	selectionMenu->CreateButton("../Assets/Dirt.png", p_spriteManager, p_drawManager, std::bind(&LevelCreationState::SelectDirt, this));
	selectionMenu->CreateButton("../Assets/Water.png", p_spriteManager, p_drawManager, std::bind(&LevelCreationState::SelectWater, this));
	selectionMenu->CreateButton("../Assets/Grass.png", p_spriteManager, p_drawManager, std::bind(&LevelCreationState::SelectGrass, this));
	selectionMenu->CreateButton("../Assets/ButtonTemplate.png", p_spriteManager, p_drawManager, std::bind(&LevelCreationState::SaveLevel, this));
	selectionMenu->CreateButton("../Assets/ButtonTemplate.png", p_spriteManager, p_drawManager, std::bind(&LevelCreationState::LoadLevel, this));
	
	Vec2 buttonPos = { 800.0f,100.0f };
	selectionMenu->SetButtonPosition(0, buttonPos);
	Vec2 buttonPos2 = { 800.0f,200.0f };
	selectionMenu->SetButtonPosition(1, buttonPos2);
	Vec2 buttonPos3 = { 800.0f, 300.0f };
	selectionMenu->SetButtonPosition(2,buttonPos3);
	Vec2 buttonPos4 = { 800.0f, 400.0f };
	selectionMenu->SetButtonPosition(3, buttonPos4);
	Vec2 buttonPos5 = { 800.0f, 500.0f };
	selectionMenu->SetButtonPosition(4, buttonPos5);

}
LevelCreationState::~LevelCreationState(){}

void LevelCreationState::SelectWater() {
	currentSprite = water;
}

void LevelCreationState::SelectDirt() {
	currentSprite = dirt;
}

void LevelCreationState::SelectGrass() {
	currentSprite = grass;
}

void LevelCreationState::SaveLevel() {
	//save grid.
	fileManager->SaveGrid(grid);
}

void LevelCreationState::LoadLevel() {
	//clear current grid.
	grid->Clear();
	//load new grid.
	fileManager->LoadGrid("Wat",grid);
}


void LevelCreationState::PlaceOnGrid() {
	int mouseX;
	int mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	Vec2 mousePos(static_cast<float>(mouseX), static_cast<float>(mouseY));
	//Need to be able to access the grid tile based on its' current position.
	std::shared_ptr<GridTile> tile = grid->AccessGridTileFromPosition(mousePos);
	if (tile.get() != nullptr) {
		switch (currentSprite) {
		case dirt:
			tile->SetSprite("../Assets/Dirt.png"); //fix hardcoded values here in some smart way.
			//set pathable to true.
			break;
		case grass:
			tile->SetSprite("../Assets/Grass.png");
			//set pathable to true.
			break;
		case water:
			tile->SetSprite("../Assets/Water.png");
			/*Also set pathable to false*/
			break;
		default:
			break; //<--- unsure if this one needed?
		}
	}
}

void LevelCreationState::Update() {
	selectionMenu->Update();

	//enter.
	Command* enter = nullptr;
	enter = inputManager->HandleMouseInput(SDL_BUTTON_LEFT);
	if (enter != nullptr) {
		PlaceOnGrid();
	}
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