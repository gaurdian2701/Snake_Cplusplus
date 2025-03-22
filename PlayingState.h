#pragma once
#include "BaseState.h"
#include "Apple.h"
class PlayingState : public BaseState
{
public:
	PlayingState(StateMachine* stateMachine, World *world);

private:
	void Init() override;
	void CreateGameObjects();
	void LoadWalls();
	void Update() override;
	void Render() override;
	void Cleanup() override;
	void ReadInput() override;
	GameObject* m_snake = nullptr;
	GameObject* m_apple = nullptr;
	World* m_world = nullptr;
	const std::vector<GameObject*>* m_gameObjects = nullptr;
	std::vector<Vector2D> m_walls;
};

