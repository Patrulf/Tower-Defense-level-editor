#pragma once
#include <memory>
#include "Sprite.h"
class SpriteManager;
class DrawManager;


//let's make into baseclass.
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Draw() = 0;
	virtual void Update() = 0;


private:
	DrawManager* _drawManager; //also get us a fookin inputmanager?
	std::shared_ptr<Sprite> _sprite;
};

