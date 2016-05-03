#ifndef TEAMAI_H
#define TEAMAI_H

//#include <list>
#include "DummiesAI.h"

class TeamAI
{
public:
	TeamAI();
	~TeamAI();

	void addToOwnTeam(yam2d::GameObject* object){ ownTeam.push_back(object); };
	void addToEnemyTeam(yam2d::GameObject* object){ enemyTeam.push_back(object); };
	void addToAllCharacters(yam2d::GameObject* object){ allCharacters.push_back(object); };

	void deleteFromOwnTeam(yam2d::GameObject* object);
	void deleteFromAllCharacters(yam2d::GameObject* object);
	void deleteFromEnemyTeam(yam2d::GameObject* object);


	void update();



private:
	std::vector<yam2d::GameObject*> ownTeam;
	std::vector<yam2d::GameObject*> enemyTeam;
	std::vector<yam2d::GameObject*> allCharacters;
};

#endif