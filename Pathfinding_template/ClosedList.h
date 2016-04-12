#ifndef CLOSEDLIST_H
#define CLOSEDLIST_H

#include <vec2.h>
#include <map>

#include "SearchNode.h"

class ClosedList
{
public:
	ClosedList();
	void addToClosedList(SearchNode* node);
	bool isInClosedList(const Position &pos);
	void clear();
private:
	typedef std::map<Position, SearchNode*> ClosedListType;
	ClosedListType closedList;

};
#endif