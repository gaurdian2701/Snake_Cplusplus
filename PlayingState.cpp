#include "stdafx.h"
#include "PlayingState.h"
#include "AI_Agent.h"

PlayingState::PlayingState(StateMachine* stateMachine, World *world) : BaseState(stateMachine, world), m_world(world)
{
}

void PlayingState::Init() 
{
	CreateGameObjects();
	m_gameObjects = &(m_world->GetGameObjects());
}

void PlayingState::CreateGameObjects()
{
	m_snake = new Snake(m_stateMachine, m_world, new PlayerAgent(0));
	m_apple = new Apple(m_world, m_snake);
	AI_Agent* snakeAIAgent = new AI_Agent();
	m_snakeAI = new Snake(m_stateMachine, m_world, snakeAIAgent);
	snakeAIAgent->SetTargetObject(m_snakeAI);
	snakeAIAgent->SetGoal(Vector2D(m_apple->GetPosition().x, m_apple->GetPosition().y));
}

void PlayingState::Update() 
{
	for (GameObject* gameObject : *m_gameObjects)
	{
		if (!gameObject->IsDestroyed())
			gameObject->Update();
	}
	ReadInput();
}

void PlayingState::Render() 
{
	for (GameObject* gameObject : *m_gameObjects)
	{
		if(!gameObject->IsDestroyed())
			gameObject->Render();
	}
}

void PlayingState::Cleanup() 
{
	m_world->DestroyGameObject(m_snake);
	m_world->DestroyGameObject(m_apple);
	delete(m_snake);
	delete(m_apple);
}

void PlayingState::ReadInput() 
{
}