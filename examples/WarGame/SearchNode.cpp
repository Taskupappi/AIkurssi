#include "SearchNode.h"

SearchNode::SearchNode(const Position &currentPosition, float H, float deltaG, SearchNode* prev)
	:prevNode(0), pos(currentPosition), H(H), G(0)
{
	resetPrev(prev, deltaG);
}

void SearchNode::resetPrev(SearchNode *prev, float deltaG)
{
	prevNode = prev;
	if (prev == nullptr)	
		G = 0.0f;
	else
		G = deltaG + prev->G;

	F = G + H;
}

float SearchNode::distance() const
{
	return F;
}

bool SearchNode::lessThan(SearchNode *n1, SearchNode *n2)
{
	return n1->distance() > n2->distance();
}