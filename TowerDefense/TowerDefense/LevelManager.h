#pragma once
#include "StateMachine.h"
#include "LevelCreationState.h"
#include "MainMenuState.h"
#include <memory>

class LevelManager
{
public:
	LevelManager();
	~LevelManager();
	
	void AddLevel(std::string p_id, std::shared_ptr<State> p_level);
	void Update();
	void Draw();
	void TransitionToLevel(std::string p_id);

	/*
	isRunning behavior does not really belong to a levelManager.
	*/
	bool GetIsRunning();
	void SetIsRunning(bool p_state);

private:
	bool isRunning;
	StateMachine* stateMachine;
	std::string currentStateID;
	std::string transitionStateID;

	std::shared_ptr<LevelCreationState> levelCreationState;
	std::shared_ptr<MainMenuState> mainMenuState;
};

