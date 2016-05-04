#ifndef PATHFINDING_APP_H_
#define PATHFINDING_APP_H_

//#include <Object.h>
//#include <es_util.h>
//#include <StreamTexture.h>
//#include <Sprite.h>
#include <SpriteBatch.h>
//#include <SpriteSheet.h>

#include "OpenList.h"
#include "ClosedList.h"
#include "SearchLevel.h"

#include <AIMapLayer.h>


class Pathfinding : public yam2d::Object
{
public:
	Pathfinding();
	virtual ~Pathfinding();

	// Updates the app
	bool update(slm::vec2 position, float deltaTime);

	void setMoveLayer(AIMapLayer* mapLayer);

private:
	yam2d::Ref<yam2d::SpriteBatchGroup> batch;

	bool searchCompleted;
	float searchTimer;

	bool doPathfinding(int startX, int startY, int endX, int endY);

	AIMapLayer* mapLayer;
};
#endif

