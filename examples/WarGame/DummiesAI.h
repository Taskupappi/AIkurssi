#ifndef DUMMIESAI_H
#define DUMMIESAI_H

#include "GameEvents.h"
#include "PlayerController.h"



//pathfinding
#include "OpenList.h"
#include "ClosedList.h"
#include "SearchLevel.h"

#include <Object.h>
#include <es_util.h>
#include <StreamTexture.h>
#include <Sprite.h>
#include <SpriteBatch.h>
#include <SpriteSheet.h>

namespace
{
	void setPathColor(yam2d::StreamTexture* t, int x, int y)
	{
		t->getPixel(x, y)[0] = 0xff;
		t->getPixel(x, y)[1] = 0x00;
		t->getPixel(x, y)[2] = 0xff;
	}

	bool isRed(unsigned char* p)
	{
		return p[0] > 200;
	}

	bool isGreen(unsigned char* p)
	{
		return p[1] > 200;
	}

	bool isBlue(unsigned char* p)
	{
		return p[2] > 200;
	}
}

class Dummies : public CharacterController
{
public:
	Dummies(yam2d::GameObject* owner, GameController* gameController, BotType botType);

	virtual ~Dummies(void);

	virtual void onMessage(const std::string& msgName, yam2d::Object* eventObject);

	void setMoveTargetObject(const yam2d::GameObject* gameObjectToGo, float reachTolerance);

	void resetMoveTargetObject();

	void setTargetToShoot(const yam2d::GameObject* gameObjectToShoot, float predictionDistance, float aimTolerance);


	void resetTargetToShoot();

	// This virtual method is automatically called byt map/layer, when update is called from main.cpp
	virtual void update(float deltaTime);
	

	float getDistanceToDestination() const;

private:
	const yam2d::GameObject* m_gameObjectToGo;
	float m_reachTolerance;
	float m_distanceToDestination;
	bool m_collisionToHomeBase;

	const yam2d::GameObject* m_gameObjectToShoot;
	float m_predictionDistance;
	float m_aimTolerance;
	
	//pathfinding
	bool doPathfinding(int startX, int startY, int endX, int endY);

	//Variables for pathfinding
	OpenList openList;
	ClosedList closedList;
	SearchLevel searchLevel;
	SearchNode* result;

	//these are not necessarily needed
	yam2d::Ref<yam2d::Texture> textureStartCase;
	yam2d::Ref<yam2d::StreamTexture> texturePathFound;
	yam2d::Ref<yam2d::Sprite> spriteStartCase;
	yam2d::Ref<yam2d::Sprite> spritePathFound;

	bool searchCompleted;
	float searchTimer;
};

#endif