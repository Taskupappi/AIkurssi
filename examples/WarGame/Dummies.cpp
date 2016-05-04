#include "DummiesAI.h"

Dummies::Dummies(yam2d::GameObject* owner, GameController* gameController, BotType botType)
	: CharacterController(owner, gameController, botType)
	, m_gameObjectToGo(0)
	, m_reachTolerance(0.0f)
	, m_distanceToDestination(0.0f)
	, m_collisionToHomeBase(false)
	, m_gameObjectToShoot(0)
	, m_predictionDistance(0.0f)
	, m_aimTolerance(0.0f)
	, searchLevel(textureStartCase)
{

}

Dummies::~Dummies(void)
{
}

void Dummies::onMessage(const std::string& msgName, yam2d::Object* eventObject)
{
	// Call base class onMessage
	CharacterController::onMessage(msgName, eventObject);
	if (msgName == "Collision")
	{
		CollisionEvent* collisionEvent = dynamic_cast<CollisionEvent*>(eventObject);
		assert(collisionEvent != 0);
		assert(collisionEvent->getMyGameObject() == getGameObject());
		yam2d::GameObject* otherGo = collisionEvent->getOtherGameObject();
		std::string otherType = otherGo->getType();
		if (otherType == "HomeBase")
		{
			if (hasItem())
			{
				dropItem1();
			}
		}
	}
}

void Dummies::setMoveTargetObject(const yam2d::GameObject* gameObjectToGo, float reachTolerance)
{

	if (gameObjectToGo == 0)
	{
		resetMoveTargetObject();
		return;
	}

	m_gameObjectToGo = gameObjectToGo;
	m_reachTolerance = reachTolerance;
	m_distanceToDestination = slm::length(m_gameObjectToGo->getPosition() - getGameObject()->getPosition());
	preferPickItem();
}

void Dummies::resetMoveTargetObject()
{
	m_gameObjectToGo = 0;
	m_reachTolerance = 0.0f;
	m_distanceToDestination = 0.0f;
	stop();
}

void Dummies::setTargetToShoot(const yam2d::GameObject* gameObjectToShoot, float predictionDistance, float aimTolerance)
{
	m_gameObjectToShoot = gameObjectToShoot;
	m_predictionDistance = predictionDistance;
	m_aimTolerance = aimTolerance;
}

void Dummies::resetTargetToShoot()
{
	m_gameObjectToShoot = 0;
	m_predictionDistance = 0.0f;
	m_aimTolerance = 0.0f;
}

void Dummies::update(float deltaTime)
{
	// Call update to base class
	CharacterController::update(deltaTime);
	if (m_gameObjectToShoot != 0)
	{
		float rotation = m_gameObjectToShoot->getRotation();
		slm::vec2 enemyForwardDir;
		enemyForwardDir.x = cosf(rotation);
		enemyForwardDir.y = sinf(rotation);
		autoUsePrimaryWeapon(m_gameObjectToShoot->getPosition() + m_predictionDistance*enemyForwardDir, m_aimTolerance);

		//if (hasCooledDownSecondary() == true)
		//{
		//	tryUseSecondaryWeapon();
		//}

	}

	// Call update to base class
	//CharacterController::update(deltaTime);
	if (m_gameObjectToGo != 0)
	{
		// Move to position
		m_distanceToDestination = moveDirectToPosition(m_gameObjectToGo->getPosition(), m_reachTolerance);
	}

	// If has collided to home base, then drop bomb.
	if (m_collisionToHomeBase)
	{
		// Obly if I has flag
		if (hasItem())
		{
			dropItem1();
		}

		m_collisionToHomeBase = false;
	}
}


float Dummies::getDistanceToDestination() const
{
	return m_distanceToDestination;
}


bool Dummies::doPathfinding(int startX, int startY, int endX, int endY)
{
	// Set color for start and end pos to path color
	path::setPathColor(texturePathFound, startX, startY);
	path::setPathColor(texturePathFound, endX, endY);

	bool done = true;
	
	//some variables for pathfinding
	OpenList openList;
	ClosedList closedList;
	SearchLevel searchLevel(textureStartCase);
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

			//3. for each square T in S's walkable adjacent tiles:
			std::vector<Position> adjacentNodes = searchLevel.GetAdjacentNodes(prev->pos.first, prev->pos.second);

			for (size_t i = 0; i < adjacentNodes.size(); i++)
			{
				//if T is in the closed list : ignore it
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
		path::setPathColor(texturePathFound, result->pos.first, result->pos.second);
		result = result->prevNode;
	}

	return true;
}