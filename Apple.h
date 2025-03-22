#pragma once
#include "Snake.h"
class Apple : public GameObject
{
public:
	Apple(World* world, GameObject *snake);
	void Update() override;
	void Render() override;
	void Destroy() override;

private:
	Snake* m_snake = nullptr;
	void RandomizePosition();
	void OnCollision(GameObject* other) override;
};

