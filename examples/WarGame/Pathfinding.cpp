#include "PathFinding.h"
#include <Input.h>
#include <ElapsedTimer.h>
#include <StreamTexture.h>
#include <Text.h>

#include "OpenList.h"
#include "ClosedList.h"
#include "SearchLevel.h"
#include "SearchNode.h"


Pathfinding::Pathfinding()
	:batch(), searchTimer(0.0f), searchCompleted(false)
{
	batch = new yam2d::SpriteBatchGroup();
}



Pathfinding::~Pathfinding()
{
}


bool Pathfinding::update(slm::vec2 position, float deltaTime)
{
	
		// Find start and end
		int startX, startY, endX, endY;
		startX = startY = endX = endY = -1;

		// Update path find!! Set m_searchCompleted to true, when path found, so the texture data is updated.
		if (startX >= 0 && startY >= 0 && endX >= 0 && endY >= 0)
		{
			yam2d::ElapsedTimer timer;
			timer.reset();
			searchCompleted = doPathfinding(startX, startY, endX, endY);
			searchTimer += timer.getTime();
		}
		else
			return false;

	return true;
}

bool Pathfinding::doPathfinding(int startX, int startY, int endX, int endY)
{
	bool done = true;
	OpenList openList;
	ClosedList closedList;
	SearchLevel searchLevel(mapLayer);
	SearchNode *result = 0;

	//Start A* search
	//add start node to open list
	Position startPos = Position(startX, startY);
	Position endPos = Position(endX, endY);
	SearchNode *newNode = new SearchNode(startPos, searchLevel.getH(startPos, endPos), 0, 0);
	openList.insertToOpenList(newNode);


	//1. Get the square on the open list which has the lowest score. Let's call this square S (or prev)
	while (!openList.isEmpty())
	{
		SearchNode* prev = openList.removeSmallestFFromOpenList();
		if (prev->pos == endPos)
		{
			//goal found
			result = prev;
			break;
		}
		else
		{
			//2. remove S from the open list and add it to the closed list
			closedList.addToClosedList(prev);
			std::vector<Position> adjacentNodes = searchLevel.GetAdjacentNodes(prev->pos.first, prev->pos.second);

			for (size_t i = 0; i < adjacentNodes.size(); i++)
			{

				if (closedList.isInClosedList(adjacentNodes[i]))
				{
					continue;
				}

				//node
				SearchNode *node = openList.findFromOpenList(adjacentNodes[i]);

				if (node == 0)
				{
					//if T is not in the open list: Add it and compute its score.
					SearchNode *newNode = new SearchNode(adjacentNodes[i],
						searchLevel.getH(adjacentNodes[i], endPos),
						searchLevel.getG(prev, adjacentNodes[i]), prev);
					openList.insertToOpenList(newNode);
				}
				else
				{
					//if T is already in the open list : check if the F score is lower
					//when we use the current generated path to get there. If it is,
					//update its score and uptade its parent as well
					SearchNode *newNode = new SearchNode(adjacentNodes[i],
						searchLevel.getH(adjacentNodes[i], endPos),
						searchLevel.getG(prev, adjacentNodes[i]), prev);
					if (node->distance() < newNode->distance())
					{
						node->resetPrev(newNode->prevNode, searchLevel.getG(newNode->prevNode, node->pos));
					}
				}
			}
		}
	}

	if (result == 0)
	{
		printf("path not found! \n");
		return true;
	}
	while (result != 0)
	{
		//somehow make it so that the dummies can get a proper pathfinding
		//path::setPathColor(m_texturePathFound, result->pos.first, result->pos.second);
		//result = result->prevNode;
	}
	return true;
}

