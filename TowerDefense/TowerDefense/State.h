#pragma once
class State
{
public:
	State();
	virtual ~State();

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Enter() = 0;
	virtual void Exit() = 0;
};

