#pragma once
#include "Command.h"

class GameObject;

class Down : public Command
{
public:
	Down();
	~Down();

	void Execute(GameObject* p_gameObject);
};

