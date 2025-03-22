#include "stdafx.h"
#include "SnakeGameStateMachine.h"


bool World::Init()
{
	InitWindow(HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION, "WHAT A THRIIIIIIIIIIIIIILLLLLLLL");
	m_stateMachine = new SnakeGameStateMachine(this);
	return true;
}

void World::Update()
{
	m_stateMachine->StateMachine_Update();
}

void World::UpdateScore()
{
	m_score += 10;
}

int World::GetScore()
{
	return m_score;
}

void World::CheckForCollisions()
{
	m_collisions.clear();
	for (GameObject* gameObject : m_gameObjects)
	{
		Vector2D gameObjectPos = gameObject->GetPosition();
		int collisionIndex = gameObjectPos.x * HORIZONTAL_RESOLUTION + gameObjectPos.y;

		std::cout << gameObject->m_name << " Collision index: " << collisionIndex << std::endl;

		std::map<int, CollisionStruct>::iterator it = m_collisions.find(collisionIndex);

		if (it != m_collisions.end())
		{
			GameObject* gameObjectExistingInPosition = it->second.gameObject;
			gameObject->OnCollision(gameObjectExistingInPosition);
			gameObjectExistingInPosition->OnCollision(gameObject);
		}

		m_collisions[collisionIndex].frameID = 0;
		m_collisions[collisionIndex].gameObject = gameObject;
	}
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

void World::DestroyGameObject(GameObject* gameObject)
{
	gameObject->Destroy();
	for (int i = 0; i < m_gameObjects.size(); i++)
		if (m_gameObjects[i] == gameObject)
			m_gameObjects.erase(m_gameObjects.begin() + i);
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