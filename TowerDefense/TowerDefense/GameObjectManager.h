#pragma once
#include <memory>
#include "GameObject.h"
#include <vector>

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	const std::shared_ptr<GameObject> GetGameObject(); //can this be const??
	void AddGameObject();

private:

	//change to map, we'll store an id as a key?
	std::vector<std::shared_ptr<GameObject>> gameObjects;
};

