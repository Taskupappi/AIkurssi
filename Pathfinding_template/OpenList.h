#ifndef OPENLIST_H
#define OPENLIST_H

#include <vec2.h>
#include <vector>
#include <algorithm>

#include "SearchNode.h"

class OpenList
{
public:
	SearchNode* findFromOpenList(const Position &pos);
	void insertToOpenList(SearchNode* node);
	void sortOpenList();
	SearchNode* removeSmallestFFromOpenList();
	bool isEmpty();
	void clear();
private:
	typedef std::vector<SearchNode*> OpenListType;
	OpenListType openList;
};

#endif