#pragma once 
#include "BaseAgent.h"
class AI_Agent : public BaseAgent
{
public:
	AI_Agent();
	Vector2D GetNextDirection() override;
	void SetGoal(Vector2D goal);
	void SetTargetObject(GameObject* snake);
	std::vector<Vector2D> GetDirectionsToDestination();

private:
	GameObject* m_snake;
	std::vector<Vector2D> m_openList;
	std::vector<Vector2D> m_visitedPoints;
	std::vector<Vector2D> m_closedList;
	std::vector<Vector2D> m_finalList;
	Vector2D m_startingPos;
	Vector2D m_goal;

	std::vector<Vector2D> GetNeighboursOfPosition(const Vector2D position) const;
	void PreparePath();
};

