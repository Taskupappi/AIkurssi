#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include <iostream>
#include "path.h"

class SearchNode
{
public:
	SearchNode(const Position &currentPosition, float H, float deltaG, SearchNode* prev);
	~SearchNode();

	void resetPrev(SearchNode *prev, float deltaG);
	static bool lessThan(SearchNode *n1, SearchNode *n2);
	float distance() const;

	SearchNode* prevNode;
	Position pos;
	float G, H, F;
};

#endif