#pragma once
#include "GameObject.h"
class Apple : GameObject
{
public:
	Apple(World* world);
	void Update() override;
	void Render() override;
	void Destroy() override;
};

