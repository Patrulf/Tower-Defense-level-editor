#pragma once
#include <memory>
#include "Sprite.h"
#include "GameObject.h"
#include <functional>
#include <vector>
#include "Button.h"

class InputManager;
class SpriteManager;
class DrawManager;
class CollisionManager;

class Menu : public GameObject
{
public:
	Menu(InputManager* p_inputManager, SpriteManager* p_spriteManager, DrawManager* p_drawManager, CollisionManager* p_collisionManager);
	~Menu();

	void Draw();
	void Update();
	
	//Menu related functions here.
	void NavigateMenu();
	void CreateButton(std::string p_spriteFilePath, SpriteManager* p_spriteManager, DrawManager* p_drawManager, std::function<void()> p_OnUse);
	//todo: templated callback that can take variable arguments.                                                                      ^
	void SetButtonPosition(int p_buttonIndex, Vec2 p_position);


private:
	std::shared_ptr<Sprite> background;

	CollisionManager* collisionManager;
	DrawManager* drawManager;
	SpriteManager* spriteManager;
	InputManager* inputManager;

	std::vector<std::shared_ptr<Button>> buttons;
	int selectedButtonIndex; //maybe use iterator instead?
};

