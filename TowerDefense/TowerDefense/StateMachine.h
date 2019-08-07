/*
Based on a statemachine made by Jerry Jonsson in his Augustus engine.
*/
#pragma once
#include <memory>
#include <string>
#include <map>
#include "State.h"

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void AddState(std::string p_stateID, std::shared_ptr<State> p_stateToAdd);
	void ChangeState(std::string p_stateID);
	void Update();
	void Draw();

private:
	std::map<std::string, std::shared_ptr<State>> states;	
	std::shared_ptr<State> currentState;
};