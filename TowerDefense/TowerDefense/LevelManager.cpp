#include "stdafx.h"
#include "LevelManager.h"

LevelManager::LevelManager() :
	currentStateID{""},
	isRunning{true}
{
	stateMachine = new StateMachine();
}



LevelManager::~LevelManager()
{
	delete stateMachine;
	stateMachine = nullptr;
}

//Would be proper to only allow levels to be here, and not just states.
//so they'd have to be levels and states.
void LevelManager::AddLevel(std::string p_id, std::shared_ptr<State> p_level) {
	stateMachine->AddState(p_id, p_level);
}

void LevelManager::TransitionToLevel(std::string p_id) {
	transitionStateID = p_id;
}

void LevelManager::Update() {
	if (transitionStateID != currentStateID) { //this part could be part of own function I suppose.
		stateMachine->ChangeState(transitionStateID);
		currentStateID = transitionStateID;
	}
	stateMachine->Update();
}

void LevelManager::Draw() {
	stateMachine->Draw();
}

bool LevelManager::GetIsRunning() {
	return isRunning;
}

void LevelManager::SetIsRunning(bool p_state) {
	isRunning = p_state;
}
