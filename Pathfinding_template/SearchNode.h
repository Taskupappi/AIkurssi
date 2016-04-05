#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#include <iostream>

typedef std::pair<int, int> Position;

class SearchNode
{
public:
	SearchNode(const Position &currentPosition, float H, float deltaG, SearchNode* prev);
	~SearchNode();

	void resetPrev(SearchNode *prev, float deltaG);
	void lessThan(SearchNode *prev, float deltaG);
	
	SearchNode* prevNode;
	Position pos;
	float G;
	float H;
	float F;


};

#endif