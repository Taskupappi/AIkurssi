#ifndef SEARCHLEVEL_H
#define SEARCHLEVEL_H

#include <vec2.h>
#include <vector>

//yam2d texture
//#include "path.h"

#include "SearchNode.h"
#include "AIMapLayer.h"

namespace
{
	void setPathColor(AIMapLayer* t, int x, int y)
	{
		t->getPixel(x, y)[0] = 0xff;
		t->getPixel(x, y)[1] = 0x00;
		t->getPixel(x, y)[2] = 0xff;
	}

	bool isRed(unsigned char* p)
	{
		return p[0] > 200;
	}

	bool isGreen(unsigned char* p)
	{
		if (p[1] == 0)
		{
			return true;
		}
		return false;
	}

	bool isBlue(unsigned char* p)
	{
		return p[2] > 200;
	}
}

class SearchLevel
{
public:
	SearchLevel(AIMapLayer* layer);
	float getG(SearchNode* fromNode, const Position &toPos);
	float getH(const Position &fromPos, const Position &toPos);
	bool isWalkable(int posX, int posY);
	std::vector<Position>GetAdjacentNodes(int posX, int posY);

private:
	AIMapLayer* mapLayer;
};

#endif