#pragma once
#include <SDL.h>
#include <vector>
#include <map>
#include <memory>
#include "Up.h"
#include "Down.h"
#include "Enter.h"

class Command;

class InputManager
{
public:
	InputManager();
	~InputManager();
	void PollEvents(); //rename into something else?
	Command* HandleKeyboardInput(SDL_Scancode p_scanCode);
	Command* HandleMouseInput(Uint8 p_mouseButton);

	void GetMousePosition();
private:
	std::shared_ptr<Up> up;
	std::shared_ptr<Down> down;
	std::shared_ptr<Enter> enter;
	//Up* up;
	//Down* down;
	//Enter* enter;
	std::map<SDL_Scancode,SDL_Event> events; //for keyboard.
	std::map<Uint8,SDL_Event> mouseEvents;

	//std::map<Uint32, SDL_Event> mouseEvents;
};

