#pragma once
#include "Command.h"

class GameObject;

class Up : public Command
{
public:
	Up();
	~Up();

	void Execute(GameObject* p_gameObject);
};

