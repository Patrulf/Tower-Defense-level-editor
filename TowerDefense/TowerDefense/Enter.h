#pragma once
#include "Command.h"

class GameObject;


class Enter : public Command
{
public:
	Enter();
	~Enter();
	void Execute(GameObject* p_gameObject);

};

