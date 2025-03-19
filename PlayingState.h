#pragma once
#include "BaseState.h"
#include "Snake.h"
class PlayingState : public BaseState
{
public:
	PlayingState(StateMachine* stateMachine, World *world);

private:
	void Init() override;
	void CreateGameObjects();
	void Update() override;
	void Render() override;
	void Cleanup() override;
	void ReadInput() override;
	GameObject* m_snake = nullptr;
	World* m_world = nullptr;
	const std::vector<GameObject*>* m_gameObjects = nullptr;
};

