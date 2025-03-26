#include "stdafx.h"
#include "AI_Agent.h"

AI_Agent::AI_Agent() {}

void AI_Agent::SetTargetObject(GameObject* snake) { m_snake = snake; }

std::vector<Vector2D> AI_Agent::GetDirectionsToDestination()
{
	Vector2D snakePos = m_snake->GetPosition();
	m_startingPos = Vector2D(snakePos.x, snakePos.y, snakePos, m_goal);
	m_openList.push_back(m_startingPos);
	while (!m_openList.empty())
	{
		Vector2D currentPos = m_openList[0];
		int currentPosIndex = 0;

		for (int i = 1; i < m_openList.size(); i++)
		{
			if (m_openList[i].fVal <= currentPos.fVal)
			{
				if (m_openList[i].hVal < currentPos.hVal)
				{
					currentPosIndex = i;
					currentPos = m_openList[i];
				}
			}
		}

		m_openList.erase(m_openList.begin() + currentPosIndex);
		m_closedList.push_back(currentPos);

		if (currentPos - m_goal <= Vector2D(20, 20))
		{
			m_goal = currentPos;
			break;
		}

		std::vector<Vector2D> neighbours = GetNeighboursOfPosition(currentPos);
		m_visitedPoints.push_back(currentPos);


		for (int i = 0; i < neighbours.size(); i++)
		{
			if (std::find(m_closedList.begin(), m_closedList.end(), neighbours[i]) != m_closedList.end())
				continue;

			int newMovementCostToPos = currentPos.DistanceFrom(neighbours[i]);
			bool neighbourInOpenList = (std::find(m_openList.begin(), m_openList.end(), neighbours[i]) != m_openList.end());
			if (newMovementCostToPos < neighbours[i].gVal || !neighbourInOpenList)
			{
				neighbours[i].gVal = newMovementCostToPos;
				neighbours[i].hVal = neighbours[i].DistanceFrom(m_goal);
				neighbours[i].fVal = neighbours[i].gVal + neighbours[i].hVal;
				neighbours[i].Deep_SetParent(&m_visitedPoints[m_visitedPoints.size() - 1]);

				if (!neighbourInOpenList)
					m_openList.push_back(neighbours[i]);
			}
		}
		neighbours.clear();
	}
	PreparePath();
	return m_finalList;
}

std::vector<Vector2D> AI_Agent::GetNeighboursOfPosition(const Vector2D position) const
{
	std::vector<Vector2D> neighbours;
	int searchOffset = 30;
	for (int i = -searchOffset; i <= searchOffset; i += searchOffset)
	{
		for (int j = -searchOffset; j <= searchOffset; j += searchOffset)
		{
			int newPos_X = position.x + i;
			int newPos_Y = position.y + j;
			Vector2D new_neighbour = Vector2D(newPos_X, newPos_Y, m_startingPos, m_goal);
			if (newPos_X < 0 || newPos_X > HORIZONTAL_RESOLUTION || newPos_Y < 0 || newPos_Y > VERTICAL_RESOLUTION
				|| (i == 0 && j == 0) || (i != 0 && j != 0))
				continue;
			neighbours.push_back(new_neighbour);
		}
	}
	return neighbours;
}

void AI_Agent::PreparePath()
{
	m_finalList.clear();
	Vector2D* currentPosition = &m_goal;

	while (currentPosition->parent != nullptr)
	{
		m_finalList.push_back(Vector2D(currentPosition->x, currentPosition->y));
		currentPosition = currentPosition->parent.get();
	}
}

void AI_Agent::SetGoal(Vector2D goal) 
{ 
	m_goal = goal; 
	GetDirectionsToDestination();
	m_openList.clear();
	m_closedList.clear();
	m_visitedPoints.clear();
}

Vector2D AI_Agent::GetNextDirection() 
{
	for(int i = 0; i < m_finalList.size(); i++)
		DrawRectangle(m_finalList[i].x, m_finalList[i].y, 20, 20, ORANGE);
	return Vector2D();
}
