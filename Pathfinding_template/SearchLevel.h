#ifndef SEARCHLEVEL_H
#define SEARCHLEVEL_H

#include <vec2.h>
#include <vector>

//yam2d texture
//#include "path.h"

#include "SearchNode.h"

class SearchLevel
{
public:
	SearchLevel(yam2d::Texture *input);
	float getG(SearchNode *fromNode, const Position &toPos);
	float getH(const Position &fromPos, const Position &toPos);
	bool isWalkable(int posX, int posY);
	std::vector<Position>GetAdjacentNodes(int posX, int posY);

private:
	yam2d::Texture *inputTexture;
};

#endif