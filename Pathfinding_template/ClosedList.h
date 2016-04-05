#ifndef CLOSEDLIST_H
#define CLOSEDLIST_H

#include <vec2.h>

class SearchNode;

class ClosedList
{
public:
	void addToClosedList(SearchNode* node);
	bool isInClosedList();
	void clear();

};
#endif