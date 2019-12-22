#include "stdafx.h"
#include "MainMenuState.h"

#include "SpriteManager.h"
#include "DrawManager.h"
#include "InputManager.h"
#include "Menu.h"
#include "LevelManager.h"
#include "CollisionManager.h"
#include "FileManager.h"

MainMenuState::MainMenuState(InputManager* p_inputManager, SpriteManager* p_spriteManager, 
	DrawManager* p_drawManager, LevelManager* p_levelManager, CollisionManager* p_collisionManager,
	FileManager* p_fileManager)
{
	collisionManager = p_collisionManager;
	spriteManager = p_spriteManager;
	drawManager = p_drawManager;
	levelManager = p_levelManager;
	inputManager = p_inputManager;
	fileManager = p_fileManager;
}

MainMenuState::~MainMenuState()
{
}
void MainMenuState::Draw() {
	menu->Draw();
}
void MainMenuState::Update() {
	menu->Update();
}

void MainMenuState::Enter() {
	menu = new Menu(inputManager, spriteManager,drawManager, collisionManager);

	std::string filePath = "../Assets/ButtonTemplate.png";
	menu->CreateButton(filePath, spriteManager, drawManager, std::bind(&MainMenuState::GoToLevelCreationState, this));
	menu->CreateButton(filePath, spriteManager, drawManager, std::bind(&MainMenuState::QuitGame, this));
}

void MainMenuState::Exit() {
	delete menu;
	menu = nullptr;
}

void MainMenuState::QuitGame(){
	levelManager->SetIsRunning(false);
} //call level manager, set quit to true.

void MainMenuState::GoToLevelCreationState(){	
	levelManager->TransitionToLevel("LevelCreation");
	//Create enum of states from engine, we'll send in as parameter ^
}


/*
Function that activates another menu, a menu that holds all the saved games and creates a button for each one.
we're gonna need scrolling as well later on D:

*/