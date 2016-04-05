#include "SearchNode.h"

SearchNode::SearchNode(const Position &currentPosition, float H, float deltaG, SearchNode* prev)
{
	prevNode = 0;
	pos = currentPosition;
	this->H = H;
	this->G = 0;
	resetPrev(prev, deltaG);
}

void SearchNode::resetPrev(SearchNode *prev, float deltaG)
{

}

void SearchNode::lessThan(SearchNode *prev, float deltaG)
{

}