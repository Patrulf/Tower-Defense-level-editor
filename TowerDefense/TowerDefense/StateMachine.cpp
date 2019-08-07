#include "stdafx.h"
#include "StateMachine.h"


StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
}

void StateMachine::ChangeState(std::string p_stateID) {
	if (currentState.get() != nullptr)
	{
		currentState->Exit();
	}
	currentState = states[p_stateID];
	currentState->Enter();
}

void StateMachine::AddState(std::string p_stateID,std::shared_ptr<State> p_stateToAdd) {
	states.insert(std::pair<std::string,std::shared_ptr<State>>(p_stateID,p_stateToAdd) );
}

void StateMachine::Update(){
	currentState->Update();
}

void StateMachine::Draw(){
	currentState->Draw();
}