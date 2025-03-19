#include "stdafx.h"
#include "SnakeGameStateMachine.h"


bool World::Init()
{
	InitWindow(1024, 720, "WHAT A THRILLLLLLLLL");
	m_stateMachine = new SnakeGameStateMachine(this);
	return true;
}

void World::Update()
{
	m_stateMachine->StateMachine_Update();
}

void World::Render()
{
	BeginDrawing();
	ClearBackground(BLACK);
	m_stateMachine->StateMachine_Render();
	EndDrawing();
}

const float World::DeltaTime() const{ return m_deltaTime; }

void World::AddGameObject(GameObject* gameObject)
{
	m_gameObjects.push_back(gameObject);
}

const std::vector<GameObject*>& World::GetGameObjects() const
{
	return m_gameObjects;
}

void World::Cleanup()
{
	for (GameObject* gameObject : m_gameObjects)
		gameObject->Destroy();
	for (GameObject* gameObject : m_gameObjects)
		delete gameObject;
	m_gameObjects.clear();

	delete m_stateMachine;
}

void World::Run()
{
	if (!Init())
	{
		std::cerr << "INIT FAILED!" << std::endl;
		return;
	}

	std::chrono::system_clock::time_point timeAtStartOfFrame = std::chrono::system_clock::now();

	while (!WindowShouldClose())
	{
		Update();
		Render();

		std::chrono::duration<double, std::milli> work_time = std::chrono::system_clock::now() - timeAtStartOfFrame;
		long timeLeftInFrame = (long)(1000 / FPS) - work_time.count();

		if (timeLeftInFrame > 0.0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(timeLeftInFrame));
		}

		m_deltaTime = std::chrono::duration<float>(std::chrono::system_clock::now() - timeAtStartOfFrame).count();
		timeAtStartOfFrame = std::chrono::system_clock::now();
	}
	CloseWindow();
	Cleanup();
}