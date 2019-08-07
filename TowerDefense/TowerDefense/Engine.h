#pragma once
#include "SDLInit.h"
#include "DrawManager.h"
#include "Display.h"
#include "InputManager.h"
#include "SpriteManager.h"
#include "Renderer.h"

class Display;

class Engine
{
public:
	Engine();
	~Engine();
private:
	SDLInit _sdl;
	InputManager* _inputManager;

	Display* _display;
	Renderer* _renderer;
	DrawManager* _drawManager;
	SpriteManager* _spriteManager;

	void GoToLevelCreationState();
};

