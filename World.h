#pragma once
#include "SnakeGameStateMachine.h"
#include "GameObject.h"

class World
{
public:
	World(SnakeGraphics *snakeGraphics);
	~World();
	void Init();
	void Update();
	void Render();
	void Cleanup();
	void KeyDown(const int key)const;

private:
	StateMachine* m_stateMachine;
	SnakeGraphics* m_snakeGraphics;
	std::vector<GameObject*> m_gameObjects;
};

