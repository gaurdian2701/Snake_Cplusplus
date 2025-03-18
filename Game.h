#pragma once
#include "stdafx.h"
class Game
{
private:
	const int FPS = 60;
	float m_deltaTime = 0.0f;

	SnakeGraphics* m_snakeGraphics = nullptr;
	SnakeGameStateMachine* m_stateMachine = nullptr;


	bool Init();
	void Update();
	void Render();
	void Cleanup();
	void KeyDownCallBack(int key) const;

public:
	void Run();	

};

