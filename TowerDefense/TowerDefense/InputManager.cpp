#include "stdafx.h"
#include "InputManager.h"
#include "Command.h"
#include "Down.h"
#include "Up.h"
#include "Enter.h"

#include <iostream>


InputManager::InputManager()
{
	up = std::make_shared<Up>();
	down = std::make_shared<Down>();
	enter = std::make_shared<Enter>();
} 

InputManager::~InputManager(){}

Command* InputManager::HandleMouseInput(Uint8 p_mouseButton) {
	auto it = mouseEvents.begin();
	for (auto itr = mouseEvents.begin(); itr != mouseEvents.end(); itr++) {
		if (itr->second.button.button == SDL_BUTTON_LEFT && p_mouseButton == SDL_BUTTON_LEFT) {
			return enter.get();
		}
	}
	return nullptr;
}

Command* InputManager::HandleKeyboardInput(SDL_Scancode p_scanCode) { 
	
	auto it = events.find(p_scanCode);

	if (it != events.end() && it->second.type == SDL_KEYDOWN) {
		if (p_scanCode == SDL_SCANCODE_UP) {
			return up.get();
		}
		if (p_scanCode == SDL_SCANCODE_DOWN) {
			return down.get();
		}
		if (p_scanCode == SDL_SCANCODE_RETURN) {
			return enter.get();
		}
	}
	return nullptr;
}

void InputManager::PollEvents(){
	events.clear();
	mouseEvents.clear();
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_KEYDOWN)
			events.insert(std::pair<SDL_Scancode, SDL_Event>(event.key.keysym.scancode,event));
		if (event.type == SDL_MOUSEBUTTONDOWN)
			mouseEvents.insert(std::pair<Uint8, SDL_Event>(event.button.button, event));
	};
}
