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

Command* InputManager::HandleKeyboardInput(SDL_Scancode p_scanCode, bool p_isKeyPress) { 
	auto it = events.find(p_scanCode);

	//problem is it registers keypress down once for a couple of seconds, so my suggestion is to
	//remove the keypress from the list if we have a down once.

	if (it != events.end() && it->second.event.type == SDL_KEYDOWN) {
		if ((p_isKeyPress == true && it->second.isKeyPress == true) || p_isKeyPress == false) {
			it->second.isKeyPress = false;
			if (p_scanCode == SDL_SCANCODE_UP) {
				return up.get();
			}
			if (p_scanCode == SDL_SCANCODE_DOWN || p_scanCode == SDL_SCANCODE_TAB) {
				return down.get();
			}
			if (p_scanCode == SDL_SCANCODE_RETURN) {
				return enter.get();
			}
		}
	}
	return nullptr;
}

void InputManager::PollEvents(){
	mouseEvents.clear();
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_KEYDOWN) {
			auto it = events.find(event.key.keysym.scancode);
			KeyboardEvent keyboardEvent;
			if (it != events.end()) {				
				it->second.event = event;
				it->second.isKeyPress = false;
				//std::cout << "We are now adding an event for holding down the key \n";
			}
			else if (it == events.end() )
			{
				//std::cout << "We are now adding an event for pressing the key once \n";
				keyboardEvent.event = event;
				keyboardEvent.isKeyPress = true;
				events.insert(std::pair<SDL_Scancode, KeyboardEvent>(event.key.keysym.scancode, keyboardEvent));
			}
			
		}			
		if (event.type == SDL_KEYUP) {
			auto it = events.find(event.key.keysym.scancode);
			if (it != events.end()) {
				events.erase(event.key.keysym.scancode);
			}
		}			
		if (event.type == SDL_MOUSEBUTTONDOWN)
			mouseEvents.insert(std::pair<Uint8, SDL_Event>(event.button.button, event));
	};
}
