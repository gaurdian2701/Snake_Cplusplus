#pragma once
class GameObject;
class StateMachine;
class World
{
private:
	const int FPS = 15;
	float m_deltaTime = 0.0f;
	StateMachine* m_stateMachine;
	std::vector<GameObject*> m_gameObjects;

	bool Init();
	void Update();
	void Render();
	void Cleanup();

public:
	void Run();
	void AddGameObject(GameObject* gameobject);
	void DestroyGameObject(GameObject* gameObject);
	const std::vector<GameObject*>& GetGameObjects() const;
	const float DeltaTime() const;
};

