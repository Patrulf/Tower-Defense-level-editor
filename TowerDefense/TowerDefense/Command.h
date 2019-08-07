#pragma once
class GameObject;

class Command
{
public:
	Command();
	virtual ~Command();
	virtual void Execute(GameObject* p_gameObject) = 0;
};

