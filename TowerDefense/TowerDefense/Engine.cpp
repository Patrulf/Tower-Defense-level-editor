#include "stdafx.h"
#include "Engine.h"
#include "ServiceLocator.h"
#include "LevelManager.h"
#include <memory>
#include "MainMenuState.h"
#include "CollisionManager.h"



#include "Vec2.h"

#include "FileManager.h"

/*TEMPINCLUDE*/
#include "Font.h"


Engine::Engine() :
	
	_sdl{}
{

	CollisionManager* collisionManager = new CollisionManager();
	_inputManager = new InputManager();
	_renderer = new Renderer();
	_spriteManager = new SpriteManager(_renderer);
	_drawManager = new DrawManager(_renderer);

	ServiceLocator<SpriteManager>::SetService(_spriteManager);
	ServiceLocator<DrawManager>::SetService(_drawManager);
	ServiceLocator<Renderer>::SetService(_renderer);

	//Vec2 gridPos(10.0f, 10.0f);
	//Grid* _grid = new Grid(gridPos, 33, 24);
	//_grid->InitGrid();

	FileManager* fileManager = new FileManager();
	//fileManager.SaveGrid("Grid");
	//fileManager.LoadGrid("Level.json");

	LevelManager* levelManager = new LevelManager();
	std::shared_ptr<MainMenuState> mainMenuState = std::make_shared<MainMenuState>(_inputManager,_spriteManager,_drawManager,levelManager, collisionManager, fileManager);
	std::shared_ptr<LevelCreationState> levelCreationState = std::make_shared<LevelCreationState>(_inputManager,_spriteManager, _drawManager, collisionManager, fileManager);

	levelManager->AddLevel("MainMenu", mainMenuState);
	levelManager->AddLevel("LevelCreation", levelCreationState);
	levelManager->TransitionToLevel("MainMenu");

	Font font("../External/fonts/FreeSans.ttf", 8);


	while (levelManager->GetIsRunning() )
	{

		_drawManager->Draw();
		levelManager->Update();
		levelManager->Draw();
		font.Draw();
		_drawManager->Present();
		_inputManager->PollEvents(); //need to poll for sdl_quit.
	}
}

void Engine::GoToLevelCreationState() {
}

Engine::~Engine()
{
	delete _renderer;
	delete _spriteManager;
	delete _drawManager;
}
