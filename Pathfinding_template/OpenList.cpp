#include "OpenList.h"

SearchNode* OpenList::findFromOpenList(const Position &pos)
{

	for (size_t i = 0; i < openList.size(); i++)
	{
		if (openList[i]->pos == pos)
		{
			return openList[i];
		}
	}

	return 0;
}

void OpenList::insertToOpenList(SearchNode* node)
{
	openList.push_back(node);
	sortOpenList();
}

void OpenList::sortOpenList()
{
	std::sort(openList.begin(), openList.end(), &SearchNode::lessThan);
}

SearchNode* OpenList::removeSmallestFFromOpenList()
{
	SearchNode* result = *(openList.end() - 1);
	openList.pop_back();
	return result;
}

bool OpenList::isEmpty()
{
	return openList.empty();
}

void OpenList::clear()
{
	openList.clear();
}
