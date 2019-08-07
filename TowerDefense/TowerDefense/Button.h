#pragma once
#include <memory>
#include "GameObject.h"
#include "Sprite.h"
#include <functional>
#include "Vec2.h"
#include "BoxCollider.h"

class SpriteManager;
class DrawManager;


class Button : public GameObject
{
public:
	Button(std::string p_spriteFilePath, SpriteManager* p_spriteManager, DrawManager* p_drawManager, std::function<void()> p_OnUse);
	~Button();
	void Update();
	void Draw();
	void OnUse();
	void MoveUp();
	void MoveDown();

	void SetSelected(bool p_state);
	bool GetSelected();

	void SetPosition(Vec2 p_position);
	Vec2 GetPosition();
	void SetDimensions(int p_width, int p_height);
	BoxCollider& GetCollider();


private:
	BoxCollider boxCollider;
	Vec2 position;
	int width;
	int height;

	SpriteManager* spriteManager;
	DrawManager* drawManager;
	std::shared_ptr<Sprite> sprite; //and also selection sprite.
	std::shared_ptr<Sprite> selectionSprite;

	std::function<void()> callback;

	bool isSelected;
};

