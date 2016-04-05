#ifndef SEARCHLEVEL_H
#define SEARCHLEVEL_H

#include <vec2.h>
#include <vector>

#include "SearchNode.h"

class SearchLevel
{
public:
	float getG(SearchNode* fromPos, SearchNode* toPos);
	float getH(SearchNode* fromPos, SearchNode* toPos);
	bool isWalkable(int x, int y);
	std::vector<slm::vec2>GetAdjacentNodes(int posX, int posY);

private:
};

#endif