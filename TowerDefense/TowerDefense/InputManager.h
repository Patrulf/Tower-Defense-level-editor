#pragma once
#include <SDL.h>
#include <vector>
#include <map>
#include <memory>
#include "Up.h"
#include "Down.h"
#include "Enter.h"

class Command;

struct KeyboardEvent {
	SDL_Event event;
	bool isKeyPress;
};

class InputManager
{
public:
	InputManager();
	~InputManager();
	void PollEvents(); //rename into something else?
	Command* HandleKeyboardInput(SDL_Scancode p_scanCode, bool p_isPressed);
	Command* HandleMouseInput(Uint8 p_mouseButton);

	void GetMousePosition();
private:
	std::shared_ptr<Up> up;
	std::shared_ptr<Down> down;
	std::shared_ptr<Enter> enter;
	//Up* up;
	//Down* down;
	//Enter* enter;
	std::map<SDL_Scancode,KeyboardEvent> events; //store if recently pressed or not too?

	std::map<Uint8,SDL_Event> mouseEvents; //store if recently pressed or not too?

	//std::map<Uint32, SDL_Event> mouseEvents;
};

