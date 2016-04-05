#include "SearchLevel.h"

float SearchLevel::getG(SearchNode* fromPos, SearchNode* toPos)
{
	return 1.f;
}

float SearchLevel::getH(SearchNode* fromPosm, SearchNode* toPos)
{
	return 1.f;
}

bool isWalkable(int x, int y)
{
	return true;
}

std::vector<slm::vec2> SearchLevel::GetAdjacentNodes(int posX, int posY)
{
	
}