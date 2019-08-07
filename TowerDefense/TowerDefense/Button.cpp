#include "stdafx.h"
#include "Button.h"
#include "DrawManager.h"
#include "SpriteManager.h"



Button::Button(std::string p_spriteFilePath,SpriteManager* p_spriteManager, DrawManager* p_drawManager, std::function<void()> p_onUse) :
	isSelected{false},
	boxCollider{1,1,1,1} //NUMBERS HERE.
{
	drawManager = p_drawManager;
	spriteManager = p_spriteManager;

	sprite = spriteManager->CreateSprite(p_spriteFilePath);

	std::string selectionFilePath = "../Assets/ButtonSelectedTemplate.png";
	selectionSprite = spriteManager->CreateSprite(selectionFilePath); //todo, make constructor parameter?
	callback = p_onUse;

}

Button::~Button() {}

void Button::SetPosition(Vec2 p_position) {
	position = p_position;
	SDL_Rect spriteRect;
	spriteRect.w = width;
	spriteRect.h = height;
	spriteRect.x = position.x;
	spriteRect.y = position.y;
	sprite->SetRect(spriteRect);
	selectionSprite->SetRect(spriteRect);
	boxCollider.UpdateCollider(position.x + width/2, position.y + height/2, width, height);
} //not happy with this function.

void Button::SetDimensions(int p_width, int p_height) {
	width = p_width;
	height = p_height;
	SDL_Rect spriteRect;
	spriteRect.w = width;
	spriteRect.h = height;
	spriteRect.x = position.x;
	spriteRect.y = position.y;
	boxCollider.UpdateCollider(position.x + width/2, position.y + height/2, width, height);
} //not happy with this function.

Vec2 Button::GetPosition() {
	return position;
}

BoxCollider& Button::GetCollider() {
	return boxCollider;
}

void Button::OnUse() {
	if (isSelected)
		callback();
}

void Button::Update() {

}

void Button::Draw() {
	if (isSelected)
		drawManager->DrawSprite(selectionSprite.get());
	else
		drawManager->DrawSprite(sprite.get());
}

void Button::SetSelected(bool p_state) {
	isSelected = p_state;
}

bool Button::GetSelected() {
	return isSelected;
}