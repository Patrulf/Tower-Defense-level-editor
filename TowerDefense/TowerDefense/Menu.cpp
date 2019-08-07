#include "stdafx.h"
#include "Menu.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "InputManager.h"
#include "CollisionManager.h"

#include "Command.h"
#include <iostream>
#include "Vec2.h"

//Could be renamed to button manager i guess?
/*
This class should have a button manager, and a canvas.
*/
Menu::Menu(InputManager* p_inputManager, SpriteManager* p_spriteManager, DrawManager* p_drawManager, CollisionManager* p_collisionManager) :
	selectedButtonIndex{0}
{
	inputManager = p_inputManager;
	spriteManager = p_spriteManager;
	drawManager = p_drawManager;
	collisionManager = p_collisionManager;

	std::string filePath = "../Assets/Test.png";
	background = spriteManager->CreateSprite(filePath);
}

Menu::~Menu()
{
}

void Menu::Update() {
	NavigateMenu();
}

void Menu::Draw() {
	drawManager->DrawSprite(background.get());

	for (int i = 0; i < (int)buttons.size(); i++) {
		buttons[i]->Draw();
	}
}

void Menu::NavigateMenu() {
	//this whole function should probably be improved upon.

	//Todo: we should make use of the command->execute.
	//also in inputmanager, releasing of key should not count as input here.
	if ((int)buttons.size() > 0) {
		Command* moveUp = inputManager->HandleKeyboardInput(SDL_SCANCODE_UP);		
		if (moveUp != nullptr) {
			buttons[selectedButtonIndex]->SetSelected(false);
			selectedButtonIndex++;

			if (selectedButtonIndex >= (int)buttons.size() - 1) {
				selectedButtonIndex = 0;
				buttons[selectedButtonIndex]->SetSelected(true);
			}
		}

		Command* moveDown = inputManager->HandleKeyboardInput(SDL_SCANCODE_DOWN);		
		if (moveDown != nullptr) {
			buttons[selectedButtonIndex]->SetSelected(false);
			selectedButtonIndex--;
			if ((int)selectedButtonIndex <= 0) {
				selectedButtonIndex = buttons.size() - 1;
				buttons[selectedButtonIndex]->SetSelected(true);
			}
		}
		
		//we quit the game, even when other one is selected?
		Command* enter = nullptr;
		for (int i = 0; i < buttons.size(); i++) {
			int mouseX;
			int mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);
			Vec2 mousePos(static_cast<float>(mouseX), static_cast<float>(mouseY) );
			
			if (collisionManager->Collision(mousePos, buttons[i]->GetCollider())) {
				buttons[selectedButtonIndex]->SetSelected(false);
				selectedButtonIndex = i;
				buttons[selectedButtonIndex]->SetSelected(true);

				enter = inputManager->HandleMouseInput(SDL_BUTTON_LEFT);
				if (enter == nullptr)
					enter = inputManager->HandleKeyboardInput(SDL_SCANCODE_RETURN);
			}
		}

		if (enter != nullptr) {
			buttons[selectedButtonIndex]->OnUse();
		}
	}
}


//todo: add overload where you can pass position as argument?
void Menu::CreateButton(std::string p_spriteFilePath, SpriteManager* p_spriteManager, DrawManager* p_drawManager, std::function<void()> p_onUse) {
	buttons.push_back(std::make_shared<Button>(p_spriteFilePath, p_spriteManager, p_drawManager, p_onUse));
	
	//here we'd want the screen dimensions.
	Vec2 position(100.0f,buttons.size() * 100.0f + 100.0f);
	buttons[buttons.size() - 1]->SetDimensions(128, 64);
	buttons[buttons.size() - 1]->SetPosition(position);

	if (buttons.size() == 1) {
		buttons[0]->SetSelected(true);
	}
}

void Menu::SetButtonPosition(int p_buttonIndex,Vec2 p_position) {
	//Make sure if index is out of range to tell us so.
	buttons[p_buttonIndex]->SetPosition(p_position);
}