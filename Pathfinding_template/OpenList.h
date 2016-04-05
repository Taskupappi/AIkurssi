#ifndef OPENLIST_H
#define OPENLIST_H

#include <vec2.h>
class SearchNode;

class OpenList
{
	SearchNode* findFromOpenList(slm::vec2 pos);
	void insertToOpenList(SearchNode* node);
	void sortOpenList();
	SearchNode* removeSmallestFFromOpenList();
	bool isEmpty();
	void clear();
};

#endif