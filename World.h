#pragma once
class GameObject;
class StateMachine;
class World
{
private:
	const int FPS = 15;
	int m_score = 0;
	float m_deltaTime = 0.0f;
	StateMachine* m_stateMachine;
	std::vector<GameObject*> m_gameObjects;
	std::map<int, CollisionStruct> m_collisions;

	bool Init();
	void Update();
	void CheckForCollisions();
	void Render();
	void Cleanup();

public:
	void Run();
	void AddGameObject(GameObject* gameobject);
	void DestroyGameObject(GameObject* gameObject);
	void UpdateScore();
	int GetScore();
	const std::vector<GameObject*>& GetGameObjects() const;
	const float DeltaTime() const;
};

